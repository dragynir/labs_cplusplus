#include"creator.h"
#include<algorithm>
#include<vector>


namespace Creator {

	bool comp(std::pair<std::string , int> a , std::pair<std::string , int> b){
		return (a.second > b.second);
	}

	void fill_file(std::ofstream& output_file, std::map<std::string, int>& words_data , int count) {
		std::vector<std::pair<std::string , int>> out_data(words_data.begin() , words_data.end());
		double words_count = count;

		std::sort(out_data.begin() , out_data.end() , comp);

		char separator = ',';
		
		output_file << "Word" << separator << "Count" << separator << "Percentages" << std::endl;
		
		for (auto data : out_data) {
			std::string out_word = data.first;
			output_file << out_word << separator << data.second << separator << (data.second / words_count) << std::endl;
		}

	}
}