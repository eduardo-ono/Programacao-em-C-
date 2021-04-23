#include <iostream>

using namespace std;

template<typename T>
void trocar(T& a, T& b )
{
    T aux;
    aux = a;
    a = b;
    b = aux;
}

int main()
{
    int a = 1, b = 2;
    trocar<int>(a, b); // trocar(a, b);
    cout << a << " " << b << endl;

    float x = 10, y = 20;
    trocar(x, y); // trocar<float>(x, y);
    cout << x << " " << y << endl;

    string fruta1 = "abacaxi", fruta2 = "caju";
    trocar(fruta1, fruta2); // trocar(x, y);
    cout << fruta1 << " " << fruta2 << endl;

    return 0;
}
