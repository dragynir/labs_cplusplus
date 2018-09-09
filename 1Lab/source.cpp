#include"TritSet.h"





int main() {
	TritSet set1(10);
	TritSet set2(10);
	set1.resize(2);
	for (int i = 0; i < set1.capacity(); ++i) {
		set1[i] = True;
	}
	for (int i = 0; i < set2.capacity(); ++i) {
		set2[i] = False;
	}

	TritSet set3 = (set1 | set2);

	for (int i = 0; i < set3.capacity(); ++i) {
		std::cout << set3[i] << "\n";
	}
	Trit a;
	a = True;
	std::cout << a;
	system("pause");
	return 0;
}