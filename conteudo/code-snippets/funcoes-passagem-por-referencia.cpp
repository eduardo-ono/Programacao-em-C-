#include <iostream>

using namespace std;

// C-style
void f1(int* num)
{
    *num = 10;
}

// C++
void f2(int& num)
{
    num = 20;
}

int main()
{
    int num = 5;

    f1(&num);
    cout << num << endl;

    f2(num);
    cout << num << endl;
}
