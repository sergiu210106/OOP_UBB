#include "../header/dynamicarray.h"

#include <stdlib.h>

DynamicArray createArray(){
    DynamicArray array;
    array.capacity = 2;
    array.length = 0;
    array.data = (TElem*)malloc(array.capacity * sizeof(TElem))
	return array;
}

void destroyArray(DynamicArray* array) {
	free(array->data);
}
int size(DynamicArray* array) {
	return array->length;
}

int search(DynamicArray* array, TElem elem) {
	for (int i=0; i<array->length; i++) {
		if (array->data[i] == elem) {
			return i;
		}
	}
	return -1;
}

void resize(DynamicArray* array) {
	int newCapacity = 2 * array->capacity;
	TElem* newData = (TElem*)malloc(newCapacity * sizeof(TElem));
	for (int i=0; i < array->length; i ++) {
		newData[i] = array->data[i];
	free(array->data);
	array->data = newData;
	array->capacity = newCapacity;
}

void addToEnd(DynamicArray* array, TElem elem){
	if (array->length == array->capacity) {
		resize(array);
	}
	array->data[array->length++] = elem;
}


