#pragma once
#include <string>
class Lamp {
private:
	std::string m_name;
		int m_number;
public:
	Lamp();
	Lamp(int number, const std::string& name);
	bool operator <(const Lamp& otherLamp);
	const std::string&	GetName() const;
	int GetNumber() const;
	void SetName(const std::string& newName);
	void SetNumber(int newNumber);
	void Print() const;
};
std::ostream& operator <<(std::ostream& outputStream, const Lamp& notebook);