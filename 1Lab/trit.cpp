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
	set_new_value(obj  , (unsigned char)1 << (sizeof(unsigned char) * 8 - right_bit));
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


void Trit::set_new_value(TritType type , unsigned char pointer) {
	if (type == True) {
		set_true(pointer);
	}
	else if (type == False) {
		set_false(pointer);
	}
	else if (type == Unknown) {
		set_unknown(pointer);
	}

}

Trit& Trit::operator=(TritType type) {
	unsigned char pointer = 1;
	pointer <<= (sizeof(unsigned char) * 8 - right_bit);
	if (data == nullptr) {
		data = new unsigned char;
		right_bit = 2;
		*data = 0;
		set_new_value(type , pointer);
	}
	else {
		set_new_value(type , pointer);
		init_trit();
		another = false;
	}
	return *this;
}


TritType Trit::get_type()const {
	unsigned char pointer = 1;
	pointer <<= (sizeof(unsigned char) * 8 - get_pos());
	if (pointer & get_data()) {
		return True;
	}
	else {
		pointer <<= (1);
		if (pointer & get_data()) {
			return False;
		}
		else {
			return Unknown;
		}
	}
}
void Trit::set_bit(unsigned char pointer , Trit const & obj , size_t diff) {
	if (pointer & *obj.data) {
		pointer = 1;
		pointer <<= (sizeof(unsigned char) * 8 - right_bit + diff);
		*data = *data | pointer;
	}
	else {
		pointer = 1;
		pointer <<= (sizeof(unsigned char) * 8 - right_bit + diff);
		pointer = ~pointer;
		*data = *data & pointer;
	}
}

Trit& Trit::operator=(Trit const & obj) {
	unsigned char pointer = 1;
	pointer <<= (sizeof(unsigned char) * 8 - obj.right_bit);
	set_bit(pointer, obj , 0);
	pointer <<= (1);
	set_bit(pointer, obj , 1);
	return *this;
}

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

/*const Trit& Trit::operator&(Trit const & obj) {
	TritType l_type = get_type();
	TritType r_type = obj.get_type();
	
	Trit* res_obj = new Trit();

	*res_obj = Tables::AndTable[l_type][r_type];

	return *res_obj;
}

const Trit& Trit::operator|(Trit const & obj) {
	TritType l_type = get_type();
	TritType r_type = obj.get_type();

	Trit* res_obj = new Trit();

	*res_obj = Tables::OrTable[l_type][r_type];

	return *res_obj;
}*/


const Trit& operator&(Trit const & self, Trit const & obj) {
TritType l_type = self.get_type();
TritType r_type = obj.get_type();

Trit* res_obj = new Trit();

*res_obj = Tables::AndTable[l_type][r_type];

return *res_obj;
}

bool operator==(Trit const & self, Trit const & obj) {
	TritType a = self.get_type();
	TritType b = obj.get_type();
	return a == b ? true : false;
}

const Trit& operator|(Trit const & self, Trit const & obj) {
TritType l_type = self.get_type();
TritType r_type = obj.get_type();

Trit* res_obj = new Trit();

*res_obj = Tables::OrTable[l_type][r_type];

return *res_obj;
}

Trit const & Trit::operator!() {
	TritType type = get_type();
	Trit* res_obj = new Trit();
	*res_obj = Tables::NegTable[type];
	return *res_obj;
}
Trit::~Trit()
{
	if(!another)
		delete data;
}
