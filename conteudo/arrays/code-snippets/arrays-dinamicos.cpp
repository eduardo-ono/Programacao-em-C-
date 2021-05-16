#include <iostream>

int* criarVetor1(const int N)
{
    int v[N];
    for (int i = 0; i < N; i++)
    {
        v[i] = 10 * i;
    }
    return v;
}

int* criarVetor2(const int N)
{
    int* v = new int[N];
    for (int i = 0; i < N; i++)
    {
        v[i] = 10 * i;
    }
    return v;
}

void imprimirVetor(int v[], const int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cout << "Entre com o tamanho do vetor: ";
    std::cin >> n;
    int* v = new int[n];
    // Popula o vetor v
    for (int i = 0; i < n; i++)
    {
        v[i] = 10 * i;
    }
    // Imprime o vetor
    imprimirVetor(v, n);
    // Elimina o vetor da memória
    delete[]v;
    v = NULL;

    //
    std::cout << "Entre com o tamanho do vetor: ";
    std::cin >> n;
    v = criarVetor1(n); // ERRO! Segmentation fault...
    imprimirVetor(v, n);
    delete[] v;
    v = criarVetor2(n); // OK
    imprimirVetor(v, n);
    delete[] v;
    v = NULL;

    return 0;
}
