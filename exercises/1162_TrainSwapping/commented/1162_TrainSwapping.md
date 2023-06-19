# Exercício 1162 do BeeCrowd: Train Swapping

[**Link do Problema**](https://www.beecrowd.com.br/judge/en/problems/view/1162)

## Código comentado

```
#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, vector<int>>;

// Método para juntar os vetores e contar o número de inversões
ii mergeAndCount(vector<int> A, vector<int> B) {
    int count = 0, pointA = 0, pointB = 0;
    int tamA = A.size(), tamB = B.size();
    vector<int> sorted;

    // "Ponteiros" que passam por A e B, respectivamente
    while ( pointA < tamA && pointB < tamB ) {
        if ( B[pointB] < A[pointA] ) {
            /*
                Se o valor de B na posição do seu ponteiro
                for menor que o valor de A na posição de seu
                ponteiro, somamos o número de inversões de acordo
                com sua posição, adicionamos o valor de B no vetor
                sorted e incrementamos o ponteiro de B
            */
            count += tamA - pointA;
            sorted.push_back(B[pointB]);
            ++pointB;
        } else if ( A[pointA] < B[pointB] ) {
            /*
                Se o valor de A na posição do seu ponteiro
                for menor que o valor de B na posição de seu
                ponteiro, adicionamos o valor de A no vetor
                sorted e incrementamos o ponteiro de A
            */
            sorted.push_back(A[pointA]);
            ++pointA;
        } else {
            /*
                Caso ambos os valores sejam iguais, 
                incrementamos ambos os ponteiros e 
                adicionamos ambos os valores ao vetor
                sorted
            */
            sorted.push_back(A[pointA]);
            sorted.push_back(B[pointB]);
            ++pointA;
            ++pointB;
        }
    }

    // Passando pelos elementos restantes de qualquer um dos vetores...
    for ( auto i = pointA; i < tamA; ++i ) sorted.push_back(A[i]);
    for ( auto i = pointB; i < tamB; ++i ) sorted.push_back(B[i]);

    // Retornando a contagem de inversões e o vetor ordenado
    return make_pair(count, sorted);
}

// Método recursivo de contagem de inversões
ii inversionCount(vector<int> L) {
    int tam = L.size();

    // Condição de parada: vetor com apenas um elemento
    if ( tam == 1 ) return make_pair(0, L);

    vector<int> A;
    vector<int> B;

    // Dividindo o vetor ao meio para dois vetores distintos
    int meio = ( tam % 2 == 0 ? (tam / 2) - 1 : tam / 2);
    for ( auto i = 0; i < tam; ++i ) {
        if (i <= meio) A.push_back(L[i]);
        else B.push_back(L[i]);
    }
    
    // Chamando recursivamente o inversionCount
    ii rA = inversionCount(A);
    ii rB = inversionCount(B);

    /*
        Com ambos os vetores A e B ordenados,
        chamamos o método mergeAndCount para
        que ambos sejam unidos e as inversões
        sejam contadas
    */
    ii r = mergeAndCount(rA.second, rB.second);

    // Retornando a soma das contagens de inversões e o vetor ordenado
    return make_pair(rA.first + rB.first + r.first, r.second);
}

int main() {
    int N, size, entry;
    vector<int> L;

    cin >> N;

    for ( auto i = 0; i < N; ++i ) {
        cin >> size;

        for ( auto j = 0; j < size; ++j ) {
            cin >> entry;
            L.push_back(entry);
        }

        ii counter = inversionCount(L);
        cout << "Optimal train swapping takes " << counter.first << " swaps." << endl;
    
        L.clear();
    }

    return 0;
}
```
