#include <string>
#include "Lamp.h"
#include <iostream>

Lamp::Lamp() {
	m_name = "Name";
    m_number = 0;
}
Lamp::Lamp(int number, const std::string& name) {
	m_name = name;
	m_number = number;
}
bool Lamp::operator <(const Lamp& otherLamp){
	return m_number > otherLamp.m_number;
}
const std::string&	Lamp::GetName() const {
	return m_name;
};
void Lamp::SetName(const std::string& newName) {
	m_name = newName;
};
int Lamp::GetNumber() const {
	return m_number;
};
void Lamp::SetNumber(int newNumber) {
	m_number = newNumber;
};

void Lamp::Print() const {
	std::cout << "Lamp name = " << m_name << std::endl;
	std::cout << "Number of lamps = " << m_number << std::endl;
};
std::ostream& operator << (std::ostream& outputStream,const Lamp& lamp){
	return outputStream << " Name: " << lamp.GetName() << std::endl << " Number: " << lamp.GetNumber() << std::endl;
}