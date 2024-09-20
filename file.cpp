#include "file.h"

FileSystem::FileSystem(const string& dirname) {
  root = new Node();
  root->name = dirname;
  root->isdir = true;
  root->child = {};
  pwd = getenv("HOME") + dirname;
  root->address = pwd;
  file_stack.push(root);
}

void FileSystem::touch(const string& filename) {
  Node *p = file_stack.top();
  string address;

  if(p->name == "/"){
    address = p->address + filename;
  }else{
    address = p->address + "/" + filename;
  }

  ofstream file(address);

  if(!file){
    cerr << "Error creating file: " << strerror(errno) << endl;
      return;
  }
  file.close();

  Node *f = new Node();
  f->name = filename;
  f->isdir = false;
  f->address = address;
  p->child.push_back(f);
}


void FileSystem::mk_dir(const string& dirname) {
    Node *p = file_stack.top();

    Node *d = new Node();
    d->name = dirname;
    d->isdir = true;
  if(p->name == "/"){
    d->address = p->address + dirname;
  }else{
    d->address = p->address + "/" + dirname;
  }
  p->child.push_back(d);


  if (mkdir(d->address.c_str(), 0755) == -1) {
    cerr << "Error creating directory: " << strerror(errno) << endl;
  }
}


void FileSystem::ls() {
    Node *p = file_stack.top();
    for (auto &i : p->child) {
        cout << i->name << "\t";
    }
    cout << endl;
}


void FileSystem::cd(const string& dirname) {
  if(dirname == ".."){
    if(file_stack.size() > 1) {
      file_stack.pop();
      pwd = file_stack.top()->address;
    }
  }else{

    Node *p = file_stack.top();
    for(auto &i : p->child){
      if(i->name == dirname && i->isdir){
        file_stack.push(i);
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
