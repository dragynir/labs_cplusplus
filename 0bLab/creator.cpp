#include"creator.h"
#include<algorithm>
#include<vector>


namespace Creator {

	bool comp(std::pair<std::string , int> a , std::pair<std::string , int> b){
		return (a.second > b.second);
	}

	void fill_file(std::ofstream& output_file, std::map<std::string, int>& words_data) {
		std::vector<std::pair<std::string , int>> out_data(words_data.begin() , words_data.end());

		std::sort(out_data.begin() , out_data.end() , comp);
	
		char separator = ',';
		double words_count = words_data.size();
		utput_file << "Word" << separator << "Count" << separator << "Percentages" << std::endl;
		
		for (auto data : out_data) {
			std::string out_word = data.first;
			output_file << out_word << separator << data.second << separator << data.second / words_count * 100 << std::endl;
		}

	}
}