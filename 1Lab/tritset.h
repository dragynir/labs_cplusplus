#pragma once
#include<new>
#include"Trit.h"




//01 - True
//00 - Unknown
//10 - False


class TritSet
{

private:
	enum OperationType { And, Or };
	unsigned int* data_array;
	size_t trits_capacity;//all
	size_t data_length;//all

	mutable size_t used_capacity;//settled
	mutable size_t used_length;//settled

	void set_used_capacity()const;
	void fill_unknown(size_t start, size_t end);
	void resize_data(size_t end, size_t tr_length);
	Trit execute_operation(Trit const & a, Trit const & b , OperationType type);
	TritSet& init_operation(TritSet & obj, OperationType type);

public:
	TritSet();

	TritSet(size_t alloc_trits);


	size_t capacity() const;

	size_t stated_capacity() const;

	TritSet(TritSet const& obj);

	TritSet & operator=(TritSet const& obj);

	void swap(TritSet & obj);

	Trit operator[](size_t trit_index);

	void shrink_to_fit();

	void resize(size_t new_size);/////

	TritSet& operator&(TritSet  & obj);

	TritSet& operator|(TritSet & obj);

	~TritSet();
};

