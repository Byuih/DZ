#include "ConteinerArray.h"
#include <iostream>

using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");

	ConteinerArray array(15);

	for (int i{ 0 }; i < 15; ++i)
		array[i] = i + 1;

	//array.reallocate(3);
	//array.resize(2);
	array.resize(3);
	{
		ConteinerArray b{ array };
		b = array;
		b = b;
		array = array;
	}

	for (int i{ 0 }; i < array.getLength(); ++i)
		std::cout << array[i] << ' ' << " Если всё правельно, то ты увидешь это (* ^ ω ^)" << endl;

	std::cout << '\n';


		return 0;
}
