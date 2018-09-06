#include"creator.h"


namespace Creator {

	void fill_file(std::ofstream& output_file, std::map<std::string, int>& words_data, std::map<std::string, bool>& words_need_quotes) {

		char separator = ',';
		char quote = '"';
		double words_count = words_data.size();
		output_file << "Word" << separator << "Count" << separator << "Percentages" << std::endl;
		
		for (auto data : words_data) {
			std::string out_word = data.first;
			if (words_need_quotes[data.first]) {
				out_word = quote + data.first + quote;
			}
			
			output_file << out_word << separator << data.second << separator << data.second / words_count * 100 << std::endl;

		}
}
}