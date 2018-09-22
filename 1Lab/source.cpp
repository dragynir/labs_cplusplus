#include"TritSet.h"





int main() {
	TritSet set1(10);
	TritSet set2(10);
	for (size_t i = 0; i < set1.capacity(); ++i) {
		set1[i] = True;
	}
	set1.resize(20);
	for (size_t i = 0; i < set2.capacity(); ++i) {
		set2[i] = False;
	}
	for (size_t i = 0; i < set1.capacity(); ++i) {
		std::cout << set1[i] << std::endl;
	}
	set2 = (set2 | set1);
	std::cout<<set2.cardinality(False);
	for(size_t i = 0; i < set2.capacity(); ++i){
		std::cout << set2[i] << std::endl;
	}
	//system("pause");
	return 0;
}