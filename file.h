#include <iostream>
#include <stack>
#include <sys/stat.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <errno.h>
#include <memory>


using namespace std;

struct Node {
  string name;
  bool isdir;
  string address;
  vector<shared_ptr<Node>> child;
  shared_ptr<Node> parent;
};

class FileSystem {
private:
  shared_ptr<Node> root;
  shared_ptr<Node> curr_node;
  string pwd;

public:
  FileSystem(const string &dirname);

  ~FileSystem();

  void touch(const vector<string> &args);

  void mk_dir(const vector<string> &args);

  string ls();

  void cd(const string &add);

  void getpwd();

  void deleteNode(shared_ptr<Node> &node);
};


