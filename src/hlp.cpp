#include <hlp.h>

namespace std {
std::ostream& operator<< (std::ostream& out, const vector<uint8_t>& vec)
{
	bool br;
	out << hex;
	for(int i = 0; i < vec.size(); ++i) {
		out << setfill('0') << setw(2) << static_cast<int>(vec[i]) << ' ';
		if((i + 1) % 32 == 0) {
			out << endl;
			br = true;
		} else {
			br = false;
		}
	}
	if(!br) {
		out << endl;
	}
	out << dec;
	return out;
}
}

