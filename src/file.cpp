#include <file.h>

std::vector<uint8> File::Load(std::string name)
{
	std::filesystem::path path(name);
	std::vector<uint8> vec;
	std::ifstream file(path);
	std::copy(
    	std::istream_iterator<uint8>(file),
    	std::istream_iterator<uint8>(),
    	std::back_inserter(vec));
	return vec;
}