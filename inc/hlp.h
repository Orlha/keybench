#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

namespace std {
	std::ostream& operator<< (std::ostream& stream, const vector<uint8_t>& vec);
}

class Hlp {
	public:
		static void print(string label, const vector<uint8_t> &vec) {
			
		}
	private:
};