#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

class Benchmark {
private:
    clock_t inicio;
    clock_t fim;
    double tempo;
public:
    Benchmark() {
        inicio = clock();
    };
    void stop() {
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    };
    double getTempo() {
         return tempo;
    }
    void print() {
        cout << fixed << setprecision(8) << tempo << endl;
    }
};

template <class T>
void imprimirVetor(T v, const int N)
{
    if (N <= 10000)
    {
        for (int i = 0; i < N; i++)
        {
            cout << v[i] << ' ';
        }
    }
    else
        cout << "Número de elementos > 10000 (" << N << ")";
    cout << endl << endl;
}

void popularVetor(int v[], const int N)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++)	{
        v[i] = rand() % 1000;
    }
}

int copiarVetor(int fonte[], int destino[], const int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        destino[i] = fonte[i];
    }

    return 0;
}

template <class T>
void trocar(T &x, T &y)
{
    T aux;
    aux = x;
    x = y;
    y = aux;
}

template <class T>
void selectionSort(T v[], const int N)
{
    for (int varredura = 0; varredura < N-1; varredura++)
    {
        int minIndex = varredura;
        for (int i = varredura + 1; i < N; i++)
        {
            if (v[i] < v[minIndex])
                minIndex = i;
        }
        trocar(v[varredura], v[minIndex]);
    }
}

void selectionSortModificado(int v[], const int N)
{
    int a = 0, b = N-1;

    while (a < b)
    {
        int indexMin = a;
        int indexMax = b;
        for (int i = a + 1; i < b; i++)
        {
            if (v[i] < v[a])
                trocar(v[i], v[a]);
            if (v[i] > v[b])
                trocar(v[i], v[b]);
        }
        trocar(v[a], v[indexMin]);
        trocar(v[b], v[indexMax]);
        a++;
        b--;
    }
}

int main()
{
    const int N = 50000;
    int v[N], u[N];
    // const int N = sizeof v / sizeof *v;

    popularVetor(v, N);
    cout << "Vetor original:" << endl;
    imprimirVetor(v, N); // Original

    copiarVetor(v, u, N);
    Benchmark benchSelectionSort;
    cout << "Ordenando...";
    selectionSort(u, N);
    benchSelectionSort.stop();
    cout << endl;
    imprimirVetor(u, N);
    benchSelectionSort.print();

    cout << "Ordenando...";
    Benchmark benchSelectionSortModificado;
    selectionSortModificado(v, N);
    benchSelectionSortModificado.stop();
    cout << endl;
    imprimirVetor(v, N);
    benchSelectionSortModificado.print();

    return 0;
}
