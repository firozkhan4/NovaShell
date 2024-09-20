#include <iostream>
#include <vector>
#include <unistd.h>
#include <string>
#include <sstream>
#include <sys/wait.h>

using std::cout,std::cin,std::endl,std::vector,std::string,std::cerr;

enum Command{
  EXIT,ECHO,CLEAR
};

void init(const string user);
vector<string> convert_token(string input);
void run_input(const vector<string>&arg);
