#include"TritSet.h"



std::ostream& operator<<(std::ostream& stream, Trit const & trit) {
	unsigned char pointer = 1;
	pointer <<= (sizeof(unsigned char) * 8 - trit.get_pos());
	if (pointer & trit.get_data()) {
		stream << "True";
	}
	else {
		pointer <<= (1);
		if (pointer & trit.get_data()) {
			stream << "False";
		}
		else {
			stream << "Unknown";
		}
	}
	return stream;
}



int main() {

	TritSet set(2);
	//set.resize(10);
	for (int i = 0; i < 2; ++i) {
		/*Trit cat = */(set[i] = True);
	}

	//set[3] = Unknown;
	set[0] = False;
	for (int i = 0; i < 2; ++i) {
		std::cout << set[i] << '\n';
	}

	Trit a = False;
	Trit b = a;
	std::cout << a << '\n' << b << '\n';
	set[1] = a;
	for (int i = 0; i < 2; ++i) {
		std::cout << set[i] << '\n';
	}

	system("pause");
	return 0;
}