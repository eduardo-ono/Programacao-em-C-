### Programação em C++

# Vetores (Arrays)

Prof. Eduardo Ono

<br>

  * ### Vetores (Arrays) Dinâmicos

[arrays-dinamicos.cpp](./code-snippets/arrays-dinamicos.cpp)

```cpp
    int n;
    std::cout << "Entre com o tamanho do vetor: ";
    std::cin >> n;
    // Cria o vetor v dinamicamente
    /* ERRO!
      int v[n];
    */
    int* v = new int[n];
    // Popula o vetor v
    for (int i = 0; i < n; i++)
    {
        v[i] = 10 * i;
    }
    // Imprime o vetor
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    // Elimina o vetor da memória
    delete[]v;
    v = NULL;
```

  * ### O vetor dinâmico é alocado no "heap"

  > Diferentemente de um vetor estático, um vetor dinâmico é alocado no "heap" da memória, não sendo eliminado após o término de uma função onde foi criado.

```cpp
int* criarVetor1(const int N)
{
    int v[N]; // !!! "Objeto" vetor criado localmente !!!
    for (int i = 0; i < N; i++)
    {
        v[i] = 10 * i;
    }
    return v;
}

int* criarVetor2(const int N)
{
    int* v = new int[N]; // Objeto vetor criado no "heap"
    for (int i = 0; i < N; i++)
    {
        v[i] = 10 * i;
    }
    return v;
}

int main()
{
    int n;
    int* v;
    std::cout << "Entre com o tamanho do vetor: ";
    std::cin >> n;
    v = criarVetor1(n); // !!! ERRO !!! Segmentation fault...
    imprimirVetor(v, n);
    delete[]v;
    v = criarVetor2(n); // OK
    imprimirVetor(v, n);
    delete[]v;
    v = NULL;
    return 0;
}
```

<br>

## Referências Bibliográficas

<br>
