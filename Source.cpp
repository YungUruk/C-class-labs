#include "Lamp.h"
#include <iostream>
#include "Container.h"
using namespace std;

int main() {
	Lamp lamp(12, "belka"), lamp1(2, "hope"), lamp2(11, "police"), lamp3(4, "ipoit"), lamp4(9, "nottrue"), lamp5(2, "mistake");
	Container<Lamp> container;
	container.PushBack(lamp);
	container.PushBack(lamp1);
	container.PushBack(lamp2);
	container.PushBack(lamp3);
	container.PushBack(lamp4);
	container.PushBack(lamp5);
	container.ShowElements();

	container.Pop();
	container.ShowElements();

		
	system("pause");
	return 0;
};