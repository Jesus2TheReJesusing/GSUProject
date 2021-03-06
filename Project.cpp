#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <ctime>

using namespace std;

bool status;

class directory{
public:
	string title;
	time_t created;
	map <string, directory> children;
	string files[50];
	time_t fcreated[50];
	int numfiles = 0;
	
	directory(string a){
	    title = a;
	}
};

directory *curr;

void mkfs(void){
    map<string,directory>root;
	root.clear();
	directory a("root");
	root.insert(pair<string,directory>("root",a));
	curr = &a;
	cout<<"System has been formatted"<<endl;
}

void mkfl(string a){
    curr->files[curr->numfiles] = a;
    cout<<a<<" "<<curr->fcreated[curr->numfiles]<<endl;
    curr->numfiles++;
}

void name(string d){
cout<<d<<endl;
}

void shell_loop(void){
string input;
string command;
string parameter;
	do{
	cout<< "My_shell_WANG: ";
	getline(cin, input);
	for(int i = 0; i<input.length();i++){
	//looks for space in command line, assigns command and parameter
	if(input[i] ==' '){
	command = input.substr(0,i);
	parameter = input.substr(i+1,input.length()-1);
	break;
	}else{
	//no space, no parameter entered
	command = input;
	}
}
	if (command=="exit"){
	break;
	}
	if (command=="mkfs"){
		mkfs();
	}
	if (command=="name"){
	if(parameter == "" ){
	cout<<"no parameter"<<endl;}
	else{
	name(parameter);
	}
	}
	}while(status = 1);
}

int main(){//initializes the shell loop 
cout<<"Welcome to CSCI 3232 shell file system!\n";

shell_loop();

cout<<"bye"<<endl;

return EXIT_SUCCESS;
}


