#pragma once
#include "Lamp.h"
#include <iostream>
using namespace std;
 template<typename T>
class Container{
private:
	struct Stack
	{
		Stack(T lamp, Stack *next = nullptr);//первый элемент стека
		Stack *m_next;
		Lamp m_data;
	}*m_head;
	int m_size;
public:

	Container();//сделать пустой контейнер
	Container(const Container& other);//сделать полный контейнер
	~Container();

	int GetSize() const;
	void PushBack(const T& lamp);
	void ShowElements() const;
	void Pop();//Извлечение элемента из вершины

	Container &operator = (const Container &other);//оператор присваивания
};

template<typename T>
Container<T>::Container()
{
	int m_size = 0;
	m_head = nullptr;
}
template<typename T>
Container<T>::Stack::Stack(T ticket, Stack *next)
{
	m_next = next;
	m_data = ticket;

}
template<typename T>
Container<T>::Container(const Container& other)
{
	Stack *stack = other.m_head;
	Stack *current;

	while (stack != nullptr)
	{

		if (m_head == nullptr)
		{

			m_head = new Stack(stack->m_data);
		}
		else
		{
			current = new Stack(stack->m_data);
			current->m_next = m_head;
			m_head = current;
		}
		stack = stack->m_next;
	}
}
template<typename T>
Container<T>::~Container()
{
	Stack *current = m_head;
	Stack* stack;

	if (current == NULL)
	{
		return;
	}
	while (current != nullptr)
	{
		stack = current;
		current = stack->m_next;
		delete stack;

	}
	m_head = nullptr;
}

template<typename T>
int Container<T>::GetSize() const
{
	return m_size;
}
template<typename T>
void Container<T>::PushBack(const T& ticket)
{

	if (m_head == nullptr)
	{
		m_head = new Stack(ticket);
	}
	else
	{

		Stack *current = new Stack(ticket);
		current->m_next = m_head;
		m_head = current;
	}
	m_size++;
}
template<typename T>
void Container<T>::ShowElements() const
{
	Stack *current = m_head;
	Container container;

	if (m_size == 0)
	{
		cout << "Empty!" << endl;
		return;
	}

	cout << "~ELEMENTS~" << endl;
	while (current != nullptr)
	{
		cout << current->m_data << endl;
		current = current->m_next;
	}

}
template<typename T>
void Container<T>::Pop()
{
	Stack *current = m_head;
	if (current == nullptr)
	{
		cout << "Empty!" << endl;
	}
	else
	{
		m_head = m_head->m_next;
		delete current;

	}
	m_size--;
}

template<typename T>
Container<T>& Container<T>::operator = (const Container& other)
{
	// check for self-assignment

	if (this == &other)
	{
		return *this;
	}
	// code destructor
	this->~Container();


	if (m_head != nullptr)
	{
		m_head = nullptr;
	}
	Stack *stack = other.m_head;
	Stack *current;


	while (stack != nullptr)
	{

		if (m_head == nullptr)
		{

			m_head = new Stack(stack->m_data);

		}
		else
		{
			current = new Stack(stack->m_data);
			current->m_next = m_head;
			m_head = current;
		}
		stack = stack->m_next;
	}

	return *this;
}