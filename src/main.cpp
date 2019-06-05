#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <iterator>

#include <hlp.h>
//using namespace std;

typedef  uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef   int8_t int8;
typedef  int16_t int16;
typedef  int32_t int32;
typedef  int64_t int64;

int main()
{
	std::cout << "Hello, World;\n";
	auto T = [] () {
		std::cout << "Hello, Lambda;\n";
	};
	T();
	std::filesystem::path path("/home/lynx/.keybench");
	std::vector<uint8> vec;
	std::ifstream file(path);
	
	std::copy(
    std::istream_iterator<uint8>(file), 
    std::istream_iterator<uint8>(), 
    std::back_inserter(vec));

    Hlp::print("file", vec);

	return 0;
}
