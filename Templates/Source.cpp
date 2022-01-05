#include <iostream>
#include "Fraction.h"
#include "LinkedList.h"

using namespace std;

template <typename T>
T myMax(T num1, T num2) 
{
	if (num1 > num2)
	{
		return num1;
	}
	else { return num2; }
}


int main()
{
	int n = 5;
	int n1 = 10;
	int temp = myMax(n, n1);

	cout << "Max number is " << temp << "\n";

	//string one;
	//string two;
	//string ans = myMax(one, two);
	//
	//cout << "Max number is " << ans << "\n";


	Fraction* f1 = new Fraction(1, 2);
	Fraction* f2 = new Fraction(3, 4);

	Fraction res = myMax(*f1, *f2);


	// create linked lists
	LinkedList<double>* doubleList;

	// I am also having trouble with creating a LL object and using its methods (says it is uninitialized)

	doubleList->getNoOfItems();





	return 0;
}