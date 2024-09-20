#include <iostream>
#include <stack>
#include <sys/stat.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <errno.h>



using namespace std;

struct Node {
    string name;
    bool isdir;
    string address;
    vector<Node*> child;
};

class FileSystem {
private:
    Node *root;
    string pwd;
    stack<Node*> file_stack;

public:
    FileSystem(const string &dirname);

    void touch(const string &filename);

    void mk_dir(const string &dirname);

    void ls();

    void cd(const string &add);

    void getpwd();
};


