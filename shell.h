#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
using namespace std;

vector<string> convert_token(string input);
void run_input(const vector<string>& arg);
void init(const string user);

