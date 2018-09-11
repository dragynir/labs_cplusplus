#pragma once
#include<iostream>
enum TritType{ False , Unknown , True };
enum{UN_INT_SIZE = sizeof(unsigned int) };

namespace Tables {

	const TritType AndTable[3][3] = { { False , False , False }  ,{ False , Unknown , Unknown } ,{ False , Unknown , True } };

	const TritType OrTable[3][3] = { { False , Unknown , True }  ,{ Unknown , Unknown , True } ,{ True , True , True } };

	const TritType NegTable[3] = { True , Unknown , False };
}


class Trit
{
private:
	unsigned char* data;
	size_t right_bit;
	bool another;

	int get_data()const;//for output
	int get_pos()const;//for output
	void init_trit();
	void set_bit(unsigned char pointer, Trit const & obj, size_t diff);
	void set_new_value(TritType type, unsigned char pointer);
public:
	TritType get_type() const;

	Trit();

	Trit(TritType obj);

	Trit(Trit const & obj);

	Trit& operator=(TritType type);

	Trit& operator=(Trit const & obj);

	friend const Trit& operator&(Trit const & self, Trit const & obj);

	friend std::ostream& operator<<(std::ostream& stream, Trit const & trit);

	friend const Trit& operator|(Trit const & self, Trit const & obj);

	//const Trit& operator&(Trit const & obj);

	//const Trit& operator|(Trit const & obj);

	Trit const & operator!();

	void set_trit(unsigned int* data, size_t diff , bool another);

	void set_true(unsigned char pointer);

	void set_false(unsigned char pointer);

	void set_unknown(unsigned char pointer);

	~Trit();
};


