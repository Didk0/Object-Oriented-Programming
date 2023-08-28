#pragma once

struct DynArray
{
	void create(size_t capacity);
	void push_back(int elem);
	void resize();
	void pop_back();
	int get(size_t index);
	void remove(size_t index);
	void map(void(func)(int&));
	void filter(bool(func)(int));

	size_t m_size = 0;
	size_t m_capacity = 0;
	int* m_arr;
};