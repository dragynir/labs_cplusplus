#pragma once
#include<fstream>
#include<map>
#include<string>


namespace Creator {
	void fill_file(std::ofstream& output_file, std::map<std::string, int>& words_data, std::map<std::string, bool>& words_need_quotes);
}