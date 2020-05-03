#include <iostream>
#include "fact.h"

using namespace std;

int main()
{
	cout<<"hello Girish:" << endl;
	Factorial fact;
	cout << "Factorial is: " << fact.calculate(5) <<endl;
	
	return 0;
}