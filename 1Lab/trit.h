#pragma once
#include<iostream>
enum TritType{ True, False, Unknown };
enum{UN_INT_SIZE = sizeof(unsigned int) };





class Trit
{
private:
	unsigned char* data;
	size_t right_bit;
	bool another;
public:
	Trit();
	int get_data()const;//for output
	int get_pos()const;//for output
	void set_bit(unsigned char pointer, Trit const & obj);
	Trit(TritType obj);
	Trit(Trit const & obj);
	Trit& operator=(TritType type);
	Trit& operator=(Trit const & obj);
	void set_trit(unsigned int* data, size_t diff , bool another);
	void init_trit();
	void set_new_value(TritType type);
	void set_true(unsigned char pointer);
	void set_false(unsigned char pointer);
	void set_unknown(unsigned char pointer);
	~Trit();
};


