#include "Container.h"
#include "Lamp.h"
#include <iostream>
#include <string>

using namespace std;

Container::Container()
{
	int m_size = 0;
	m_head = nullptr;
}

Container::Stack::Stack(Lamp lamp, Stack *next)
{
		m_next = next;
		m_data = lamp;
	}

Container::Container(const Container& other)
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

Container::~Container()
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

int Container::GetSize() const
{
	return m_size;
}

void Container::PushBack(const Lamp& lamp)
{
	if (m_head == nullptr)
	{
		m_head = new Stack(lamp);
	}
	else
	{
		Stack *current = new Stack(lamp);
		current->m_next = m_head;
		m_head = current;
	}
	m_size++;
}

void Container::ShowElements() const
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

void Container::Pop()
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


Container& Container::operator = (const Container& other)
{

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

void Container::ChangeElement(const Container& container)
{
	int number;
	string name;
	int value;

	Stack *current = m_head;

	if (m_size == 0)
	{
		cout << "Empty!" << endl;
		return;
	}

	cout << "Input the number of the item you want to change: ";
	cin >> number;

	while (current != nullptr)
	{
		if (number<container.GetSize() + 1)
		{
			for (int i = 0; i < number - 1; i++)//Дойти до нужного элемента
			{
				current = current->m_next;
			}

			Lamp newLamp;
			cout << "Input new name:" << endl;
			cin >> name;
			newLamp.SetName(name);
			cout << "Input new number:" << endl;
			cin >> value;
			newLamp.SetNumber(value);
			current->m_data = newLamp;
			break;
		}
		else
		{
			cout << "More than size!!!" << endl;
			return;
		}
	}
}