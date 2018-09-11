#include "module1.h"
#include "module2.h"
#include <iostream>
 
int main(int argc, char** argv)
{
	std::cout <<  "Hello world!" << "\n";
	
	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";
	using namespace Module1;
	std::cout << getMyName() << "\n"; // (A)
	std::cout << Module2::getMyName() << "\n";

	using namespace Module2; // (B)
	std::cout << Module2::getMyName() << "\n"; // COMPILATION ERROR (C)

	using Module2::getMyName;
	std::cout << getMyName() << "\n"; // (D)
}



//1) убедился
//2)dir filename /T:W -  в windows
//3) A)John , D)James
//4) Подключается два пространства имен с одинаковыми именами функций - не понятно какую
//функцию вызывать
//5)1.переименовать функцию
//  2.использовать using объявление using Module2::getMyName
//	3.написать префикс перед getMyName - Module2::getMyName()
//	явно указав принадлежность к Module2
//6) можно написать using namespace std; - using ирективу
//	но лучше using std::cout;