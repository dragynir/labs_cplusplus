#include"handler.h"


namespace Handler{
	void set_words(std::ifstream& input_file , std::map<std::string , int>& words_data , std::map<std::string , bool>& words_need_quotes){
		std::string input_str;

		std::list<std::string> input_lines;

		while(std::getline(input_file , input_str)){
			input_lines	.push_back(input_str);
		}
		for(auto line : input_lines){
			input_str = line;
			bool in_word = false;
			std::string word = "";
			bool need_quotes = false;

			for(char s : input_str){
				if(s == ' '){
					if(in_word){
						words_data[word]++;
						words_need_quotes[word] = need_quotes;
						word = "";
						in_word = false;
						need_quotes = false;
					}else{
						continue;
					}
						
				}else{
					if(!in_word){
						in_word = true;
					}
				}
				if(s != ' '){
					word+=s;
				}
				
				if(in_word && !(isdigit(s) || isalpha(s))){
					need_quotes = true;
				}
			}

			if(word != ""){
				words_data[word]++;
				words_need_quotes[word] = need_quotes;
			}

		}

	}
}