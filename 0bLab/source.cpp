#include<fstream>
#include<cassert>
#include<regex>
#include<exception>
#include"handler.h"
#include<iostream>


namespace InputHandle{

	void check_file_format(std::string txt , std::string csv){
		std::smatch result;

		std::regex check_txt(".txt$");
		std::regex check_csv(".csv$");

		if(!std::regex_search(txt , result , check_txt)){
			std::cout << "Wrong Input File Format!" << std::endl;
			exit(1);
		}
		
		if(!std::regex_search(csv, result , check_csv)){
			std::cout << "Wrong Output File Format" << std::endl;
			exit(1);
		}
	}
}

namespace Creator {
	void fill_file(std::ofstream& output_file, std::map<std::string, int>& words_data, std::map<std::string, bool>& words_need_quotes);
}

namespace InputHandle {
	void check_file_format();
}

int main(int argc , char** argv){
	assert(argc == 3);

	std::string input_f = argv[1];
	std::string csv_f = argv[2];

	InputHandle::check_file_format(input_f , csv_f);

	std::ifstream input_file(input_f);
	std::ofstream output_file(csv_f);

	if(!input_file.is_open()){
		std::cout << "Input file not exist!" << std::endl;
		exit(1);
	}

	

	std::map<std::string , int> words_data;
	std::map<std::string, bool> words_need_quotes;
	Handler::set_words(input_file , words_data , words_need_quotes);

	Creator::fill_file(output_file, words_data, words_need_quotes);

	system("pause");
	
	return 0;
}