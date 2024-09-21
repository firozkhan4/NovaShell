#include "file.h"

FileSystem::FileSystem(const string& dirname) {
  root.reset(new Node());
  root->name = dirname;
  root->isdir = true;
  root->child = {};
  pwd = getenv("HOME");
  pwd += ("/NovaShell" + dirname);
  root->address = pwd;
  root->parent = nullptr;
  curr_node = root;
}

FileSystem::~FileSystem(){
  deleteNode(root);
  curr_node.reset();
  root.reset();

}

void FileSystem::touch(const vector<string>& args) {
  string address = curr_node->address;

  if(curr_node->name != "/"){
    address = curr_node->address + "/";
  }
  for(uint64_t i = 1; i < args.size(); i++){
    
    string curr_add = address + args[i];

    ofstream file(curr_add);

    if(!file){
      cerr << "Error creating file: " << strerror(errno) << endl;
      return;
    }
    file.close();

    shared_ptr<Node> f(new Node());
    f->name = args[i];
    f->isdir = false;
    f->address = curr_add;
    f->parent = curr_node;
    curr_node->child.push_back(move(f));

  }
}


void FileSystem::mk_dir(const vector<string>& args) {

  string address = curr_node->address;
  
  if(curr_node->name != "/"){
    address = curr_node->address + "/";
  }
  for(uint64_t i = 1; i < args.size(); i++){
    
    string curr_add = address + args[i];
  
    if (mkdir(curr_add.c_str(), 0755) == -1) {
      cerr << "Error creating directory: " << strerror(errno) << endl;
      return;
    }
    shared_ptr<Node> d(new Node());
    d->name = args[i];
    d->isdir = true;
    d->parent = curr_node;

    curr_node->child.push_back(move(d));
  }
}


string FileSystem::ls() {
  string list;
  for (auto &i : curr_node->child) {
    list += (i->name + "\t");
  }
  return list;
}


void FileSystem::cd(const string& dirname) {
  if(dirname == ".."){
    if(curr_node->name != "/") {
      curr_node = curr_node->parent;
    }
  }else{

    for(auto &i : curr_node->child){
      if(i->name == dirname && i->isdir){
        curr_node = i;
        pwd = i->address;
        return;
      }
    }
    cerr << "Directory not found: " << dirname << endl;
  }
}


void FileSystem::getpwd() {
  cout << pwd << endl;
}


void FileSystem::deleteNode(shared_ptr<Node>& node) {
    for (auto& child : node->child) {
        deleteNode(child);
    }
  node->parent.reset();
  node.reset();
}
