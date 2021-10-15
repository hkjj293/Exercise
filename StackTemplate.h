#pragma once
#include <string>
#include <iostream>

template <typename T>
void copy_items(T*& new_items, T*& old_items, int length);

template <typename T>
void move_items(T*& des, T*& src);

template <typename T>
class StackTemplate {
public:
	StackTemplate();
	~StackTemplate();
	void push(T&& val);
	T pop();
	int get_size();
	bool isEmpty();
private:
	T* items;
	size_t size;
};

template <typename T>
StackTemplate<T>::StackTemplate(){
	items = NULL;
	size = 0;
}

template <typename T>
StackTemplate<T>::~StackTemplate() {
	delete[] this->items;
	this->items = NULL;
}

template <typename T>
void StackTemplate<T>::push(T&& val) {
	T* new_items = new T[this->size + 1];
	copy_items<T>(new_items, this->items, this->size);
	new_items[this->size] = val;
	move_items<T>(this->items, new_items);
	this->size++;
}

template <typename T>
T StackTemplate<T>::pop() {
	if (this->size > 0) {
		T* new_items = new T[this->size - 1];
		copy_items<T>(new_items, this->items, this->size - 1);
		T top = this->items[this->size - 1];
		move_items<T>(this->items, new_items);
		this->size--;
		return top;
	}
	else {
		return NULL;
	}
}

template <typename T>
int StackTemplate<T>::get_size() {
	return (int)this->size;
}

template <typename T>
bool StackTemplate<T>::isEmpty() {
	return this->size <= 0;
}

template <typename T>
void copy_items(T*& des, T*& src,int length) {
	for (int i = 0; i < length; i++) {
		des[i] = std::move(src[i]);
	}
}

template <typename T>
void move_items(T*& des, T*& src) {
	delete[] des;
	des = std::move(src);
	src = NULL;
}


