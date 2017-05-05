#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
string lowercase(string input)
{
	for (int i=0; i<input.length(); i++)
		{
			input[i]=tolower(input[i]);
		}
	return input;
}
int main()
{
	int num1;
	int num2;
	int result;
	string again = "y";
	while(again == "y")
		{
			string action;
			cout << setprecision(3);
			cout << "Welcome to fosscalc, please enter your first number" << endl;
			cin >> num1;
			cout << "Please enter your second number" << endl;
			cin >> num2;
			cout << "Enter the operator, please use the full word, I.E add" << endl;
			cin >> action;
			action = lowercase(action);
			if(action == "add")
				{
					cout << "Your result is:" << num1 + num2 << endl;
				}
			else if(action == "subtract")
				{
					cout << "Your result is:" << num1 - num2 << endl;
				}
			else if(action == "multiply")
				{
					cout << "Your result is:" << num1 * num2 << endl;
				}
			else if(action == "divide")
				{
				    if(num1 <= 0 || num2 <= 0)
                    {
                        result = 0;
                    }
                    else
                    {
                        double result = num1 / num2;
                    }
					cout << "Your result is:" << result << endl;
				}
			else if(action == "sqrt")
				{
					cout << "The square root of number 1 is: " << sqrt(num1) << " And the square root of number 2 is: " << sqrt(num2) << endl;
				}
			else
				{
					cout << "Err, wrong operator." << endl;
					cout << "You entered: " << action << endl;
				}
			cout << "Would you like to calculate another number?" << endl;
			cout << "Y/N:";
			cin >> again;
			again = lowercase(again);
		}
    return 0;
}
