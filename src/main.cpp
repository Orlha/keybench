/*#########################################
 * Project: Keybench
 *    File: main.cpp
 *  Author: Sergey Moroz
 * Created: 2019.06.06
 #########################################*/

#include <iostream>
#include <map>
#include <chrono>
#include <thread>

#include <hlp.h>
#include <file.h>
#include <control.h>
#include <share.h>
using namespace std;

enum command {
	QUIT,
	AUTH,
};

static map<string,command> cmd_map = {
	{"quit", QUIT},
	{"q",    QUIT},
	{"auth", AUTH},
};

int main()
{	
	auto vec = File::Load("/home/lynx/.keybench");
    cout << "File data: " << endl << vec;

	string str;
    while(true) {	
    	cout << "keybench: ";
    	getline(cin, str);
    	if(cin.eof()) {
    		return 0;
    	}

	    auto cmd = cmd_map.find(str);
	    if(cmd == cmd_map.end()) {
	    	cout << "Invalid command;" << endl;
	    	this_thread::sleep_for(chrono::milliseconds(1000));
	    	continue;
	    }
	    switch(cmd->second) {
	    	case QUIT: {
	    		cout << "Shutdown requested;" << endl;
	    		cout << "Exiting;" << endl;
	    		return 0;
	    	}
	    	case AUTH: {
	    		cout << "Authentication requested;" << endl;
	    		cout << "Master password: ";
	    		getline(cin, str);
	    		if(cin.eof()) return 0;
	    	}
	    }
    }
	return 0;
}
