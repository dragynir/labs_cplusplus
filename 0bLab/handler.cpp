#include"handler.h"


namespace Handler{
	void set_words(std::ifstream& input_file , std::map<std::string , int>& words_data){
		std::string input_str;

		std::regex rgx("[^a-zA-Z0-9]+");

		while (std::getline(input_file, input_str)) {
			std::sregex_token_iterator iter(input_str.begin() , input_str.end() , rgx , -1);
			std::sregex_token_iterator end;
			
			for (; iter != end; ++iter) {
				std::string a = *iter;
				if(a != "")
					words_data[a]++;
			}
		}
	}
}