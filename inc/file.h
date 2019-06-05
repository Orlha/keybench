#pragma once
#include <filesystem>
#include <fstream>
#include <vector>
#include <iterator>

#include <share.h>

using namespace std;

class File {
	public:
		static std::vector<uint8> Load(string name);
};