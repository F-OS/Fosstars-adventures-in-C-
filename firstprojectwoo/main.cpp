#include <iostream>

using namespace std;

int main()
{
    int foo;
    int bar = 1;
    int a_number = 455;
    int another_number = 400;
    int64_t hi = 19045859785789453897;
    for ( int ticker = 0; ticker < 100; ticker = ticker + 1 )
    {
        cout << "Number: " << ticker << endl;
        cout << a_number << endl;
        cout << another_number << endl;
        cout << hi << endl;
    }
    return 0;
}
