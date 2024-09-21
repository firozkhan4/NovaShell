#include "shell.h"
#include "file.h"
#include <thread>

FileSystem fs("/");

vector<string> convert_token(string input){
  vector<string>args;

  std::istringstream iss(input);
  string token;
  
  while(std::getline(iss,token,' ')){
    args.push_back(token);
  }
  return args;
}

void run_input(const vector<string>& arg) {

  if(arg[0] == "clear"){

    system("clear");


  }else if(arg[0] == "echo"){


    if(arg.size() <= 1){
      cout << endl;
      return;
    }
    for (uint64_t i = 1; i < arg.size(); i++) {
      cout << arg[i] << " ";
    }
      cout << endl;

  }else if(arg[0] == "mkdir"){

    fs.mk_dir(arg);

  }else if(arg[0] == "ls"){

    string list = fs.ls();
    std::cout << list << endl;

  }else if(arg[0] == "touch"){

    fs.touch(arg);

  }else if(arg[0] == "pwd"){
    
    fs.getpwd();

  }else if(arg[0] == "cd"){
    
    fs.cd(arg[1]);

  }else
  {


    std::cout << "Input Not Found!!" << endl;


  }
}


void init(const string user){
  string input;
  vector<string> tokens;

  while(true){
    cout << user << ":~" << " ";
    std::getline(cin,input);

    tokens = convert_token(input);
 
    if(tokens[0] == "exit") return;

    thread t(run_input,tokens);

    t.join();

  }
}



