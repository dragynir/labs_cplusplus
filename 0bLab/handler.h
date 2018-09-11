#include<map>
#include<fstream>
#include<cctype>
#include<string>
#include<list>
namespace Handler{

	void set_words(std::ifstream& input_file, std::map<std::string, int>& words_data, std::map<std::string, bool>& words_need_quotes);

}