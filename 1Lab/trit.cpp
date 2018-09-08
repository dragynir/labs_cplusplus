#include "Trit.h"


/*size_t& Trit::get_pos() {
	return right_bit;
}
unsigned int*  & Trit::get_data() {
	return data;
}
*/
Trit::Trit() {
	data = nullptr;
	right_bit = 2;
	another = false;
}

Trit::Trit(TritType obj) {
	data = new unsigned char;
	right_bit = 2;
	*data = 0;
	set_new_value(obj);
}

Trit::Trit(Trit const & obj) {
	if (this != &obj) {
		if (obj.another) {
			data = obj.data;
			right_bit = obj.right_bit;
			another = true;
		}
		else {
			data = new unsigned char;
			*data = *obj.data;
			right_bit = obj.right_bit;
			another = false;
		}
	}
}



int Trit::get_data()const {
	return *data;
}
int Trit::get_pos()const {
	return right_bit;
}
void Trit::set_trit(unsigned int* d, size_t diff , bool another) {
	size_t b_pos = (diff - 1) / 8;
	right_bit = diff - b_pos * 8;
	data = ((unsigned char*)d) + b_pos;
	this->another = another;
}


void Trit::init_trit() {
	unsigned char* new_data = new unsigned char;
	*new_data = *data;
	data = new_data;
}

void Trit::set_true(unsigned char pointer) {
	*data = *data | pointer;
	pointer <<= (1);
	pointer = ~pointer;
	*data = *data & pointer;
}
void Trit::set_false(unsigned char pointer) {

	pointer = ~pointer;
	*data = *data & pointer;
	pointer = ~pointer;
	pointer <<= (1);
	*data = *data | pointer;
}

void Trit::set_unknown(unsigned char pointer) {
	unsigned int keep_p = ~pointer;
	*data = *data & keep_p;
	pointer <<= (1);
	pointer = ~pointer;
	*data = *data & pointer;
}


void Trit::set_new_value(TritType type) {

	unsigned char pointer = 1;
	pointer <<= (sizeof(unsigned char) * 8 - right_bit);
	if (type == True) {
		set_true(pointer);
	}
	else if (type == False) {
		set_false(pointer);
	}
	else if (type == Unknown) {
		set_false(pointer);
	}

}

Trit& Trit::operator=(TritType type) {
	if (data == nullptr) {
		data = new unsigned char;
		right_bit = 2;
		*data = 0;
		set_new_value(type);
	}
	else {
		set_new_value(type);
		init_trit();
		another = false;
	}
	return *this;
}

void Trit::set_bit(unsigned char pointer , Trit const & obj) {
	if (pointer & *obj.data) {
		pointer = 1;
		pointer <<= (sizeof(unsigned char) * 8 - right_bit + 1);
		*data = *data | pointer;
	}
	else {
		pointer = 1;
		pointer <<= (sizeof(unsigned char) * 8 - right_bit);
		pointer = ~pointer;
		*data = *data & pointer;
	}
}

Trit& Trit::operator=(Trit const & obj) {
	unsigned char pointer = 1;
	pointer <<= (sizeof(unsigned char) * 8 - obj.right_bit);
	set_bit(pointer, obj);
	pointer <<= (1);
	set_bit(pointer, obj);
	return *this;
}

Trit::~Trit()
{
	if(!another)
		delete data;
}
