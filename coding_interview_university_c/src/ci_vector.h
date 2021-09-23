#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	// _start_address is the address of the first item of the vector.
	int* _start_address;
	// _capacity number of items that can currently be stored in the vector.
	int _capacity;
	// _size number of items that is currently stored in the vector.
	int _size;
} ci_vector;

// ci_vector_int_init returns an empty vector.
ci_vector ci_vector_int_init() {
	ci_vector a = {._capacity = 4, ._size = 0};
	a._start_address = (int*)malloc(a._capacity);
	return a;
}

// ci_vector_int_size returns the number of elements that are currently stored
// in the vector.
int ci_vector_int_size(ci_vector* a) { return a->_size; }

// ci_vector_int_capacity returns the number of elements that can currently be
// stored in the vector.
int ci_vector_int_capacity(ci_vector* a) { return a->_capacity; }

// ci_vector_int_is_empty returns true if the vector currently contains 0
// elements.
bool ci_vector_int_is_empty(ci_vector* a) { return a->_size == 0; }

// ci_vector_int_at returns the element stored at the index location.
//
// This function is not safe and will allow you to access items outside the
// bounds of the vector in favour of the increased speed.
int ci_vector_int_at(ci_vector* a, int const index) {
	return a->_start_address[index];
}

// ci_vector_int_push appends the passed item to the end of the vector.
void ci_vector_int_push(ci_vector* a, int const item) {
	a->_start_address[a->_size++] = item;
}

// ci_vector_int_pop removes the last element of the vector and returns the
// value to the caller.
int ci_vector_int_pop(ci_vector* a) {
	return a->_start_address[a->_size-- - 1];
};

// ci_vector_int_find returns the index of the first item in the array that
// matches the passed value.
//
// If the value is not found, -1 is returned.
int ci_vector_int_find(ci_vector* a, int const item) {
	for (int index = 0; index < a->_size; ++index) {
		if (a->_start_address[index] == item) {
			return index;
		}
	}
	return -1;
}
