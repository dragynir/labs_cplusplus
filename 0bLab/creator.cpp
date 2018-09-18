#include"creator.h"


namespace Creator {

	void fill_file(std::ofstream& output_file, std::map<std::string, int>& words_data) {

		char separator = ',';
		double words_count = words_data.size();
		output_file << "Word" << separator << "Count" << separator << "Percentages" << std::endl;
		
		for (auto data : words_data) {
			std::string out_word = data.first;
			output_file << out_word << separator << data.second << separator << data.second / words_count * 100 << std::endl;
		}

	}
}