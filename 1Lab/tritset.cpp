#include "TritSet.h"

//заменить sizeof(unsigned int) - на typedef

TritSet::TritSet() {
	data_array = nullptr;
	trits_capacity = 0;
	used_capacity = 0;
	data_length = 0;
	used_length = 0;
};

TritSet::TritSet(size_t alloc_trits) {
	trits_capacity = alloc_trits;
	data_length = alloc_trits * 2 / 8 / UN_INT_SIZE;
	if ((alloc_trits * 2) % (8 * UN_INT_SIZE)) {
		data_length++;
	}
	used_capacity = 0;
	used_length = 0;
	try
	{
		data_array = new unsigned int[data_length];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
		exit(1);
	}
	fill_unknown(0 , data_length);
};




Trit TritSet::operator[](size_t trit_index) {
	if (trit_index >= trits_capacity) {
		throw std::out_of_range("hey");///////////
	}
	trit_index++;
	size_t full_index = trit_index * 2 / 8 / UN_INT_SIZE;
	size_t diff = (trit_index * 2) % (8 * UN_INT_SIZE);
	Trit wrapper;
	if (diff == 0) {
		wrapper.set_trit(data_array + full_index - 1, diff , true);
	}
	else {
		wrapper.set_trit(data_array + full_index , diff , true);
	}
	return wrapper;//check
}




Trit TritSet::execute_operation(Trit const & a , Trit const & b , OperationType type) {

	if (type == And) {
		return (a & b);
	}
	else if (type == Or) {
		return (a | b);
	}
}


TritSet& TritSet::init_operation(TritSet & obj, OperationType type) {
	TritSet* greater = nullptr;
	size_t res_trits_size;
	size_t less_size;
	if (trits_capacity > obj.trits_capacity) {
		res_trits_size = trits_capacity;
		less_size = obj.trits_capacity;
		greater = this;
	}
	else {
		res_trits_size = obj.trits_capacity;
		less_size = trits_capacity;
		greater = &obj;
	}

	TritSet* new_set = new TritSet(res_trits_size);

	for (int i = 0; i < res_trits_size; ++i) {
		if (i < less_size) {
			(*new_set)[i] = (execute_operation((*this)[i] ,   obj[i] , type));
		}
		else {
			(*new_set)[i] = (*greater)[i];
		}
	}
	return *new_set;
}


TritSet& TritSet::operator&(TritSet & obj) {
	return init_operation(obj, And);
}

TritSet& TritSet::operator|(TritSet & obj) {
	return init_operation(obj, Or);
}


TritSet::TritSet(TritSet const& obj)
	:data_length(obj.data_length) , trits_capacity(obj.trits_capacity) , used_capacity(obj.used_capacity) ,used_length(obj.used_length){
	data_array = new unsigned int[data_length];
	for (size_t i = 0; i < data_length; ++i) {
		data_array[i] = obj.data_array[i];
	}
}



TritSet & TritSet::operator=(TritSet const& obj) {

	if (this !=& obj) {
		TritSet(obj).swap(*this);
	}
	return *this;
}

void TritSet::shrink_to_fit() {
	set_used_capacity();
	resize_data(used_length , used_capacity);
}


void TritSet::resize_data(size_t end , size_t tr_length) {
	unsigned int* new_data = new unsigned int[end];
	for (size_t i = 0; i < end; ++i) {
		if (i > data_length) {
			new_data[i] = data_array[i];
		}
		else {
			new_data[i] = 0;
		}
			
	}
	delete[]data_array;
	trits_capacity = tr_length;
	data_length = end;
	data_array = new_data;
}

void TritSet::swap(TritSet & obj) {
	std::swap(trits_capacity, obj.trits_capacity);
	std::swap(used_capacity, obj.used_capacity);
	std::swap(data_array, obj.data_array);
	std::swap(data_length, obj.data_length);
	std::swap(used_length, used_length);
}

void TritSet::resize(size_t new_size) {
	size_t full_index = new_size * 2 / 8 / UN_INT_SIZE;
	size_t diff = (new_size * 2) % (8 * UN_INT_SIZE);
	if (diff) {
		full_index++;
	}
	if (full_index == data_length) {
		trits_capacity = new_size;
		return;
	}
	resize_data(full_index, new_size);
}



void TritSet::set_used_capacity() const {
	size_t diff = 0;
	for (size_t i = data_length; i > 0; --i) {
		unsigned int pointer = 1;
		for (size_t j = UN_INT_SIZE * 8; j > 0; --j) {
			if (pointer & data_array[i - 1]) {
				used_length = i;
				diff = j / 2 + 1;
				used_capacity = (i) * UN_INT_SIZE * 4 + diff;
				return;
			}
			pointer <<= (1);
		}
	}
}

void TritSet::fill_unknown(size_t start , size_t end) {
	for (size_t i = 0; i < data_length; ++i) {
		data_array[i] = 0;
	}
}


size_t TritSet::capacity() const{
	return trits_capacity;
}

size_t TritSet::stated_capacity() const {
	set_used_capacity();
	return used_capacity;
}



TritSet::~TritSet() {
	delete[] data_array;
};