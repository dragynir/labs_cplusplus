#pragma once
#include<map>
#include<fstream>
#include<string>
#include<regex>

namespace Handler{

	void set_words(std::ifstream& input_file, std::map<std::string, int>& words_data , int* count);

}