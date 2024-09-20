#include "init.h"

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
    for (int i = 1; i < arg.size(); i++) {
      cout << arg[i] << " ";
    }
      cout << endl;
  }else{
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

    pid_t pid = fork();

    if(pid == 0){
      run_input(tokens);
      exit(0);
    }else if(pid < 0){
      cerr << "Execution Failed" <<endl;
    }else{
      wait(NULL);
    }
  }
}



