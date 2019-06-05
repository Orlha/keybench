#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Hlp {
	public:
		static void print(string label, const vector<uint8_t> &vec) {
			bool br;
			cout << label << ":" << endl;
			cout << hex;
			for(int i = 0; i < vec.size(); ++i) {
				cout << setfill('0') << setw(2) << static_cast<int>(vec[i]);
				if((i + 1) % 32 == 0) {
					cout << endl;
					br = true;
				} else {
					br = false;
				}
			}
			if(!br) {
				cout << endl;
			}
			cout << dec;
		}
};