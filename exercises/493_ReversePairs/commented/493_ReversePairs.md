# Exercício 493 do LeetCode: Reverse Pairs

[**Link do Problema**](https://leetcode.com/problems/reverse-pairs/)

## Código comentado

```
#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, vector<int>>;

class Solution {
public:

    // Método para contar os "pares invertidos" e unir ambos os lados do vetor passados
    int mergeAndCountInversions(vector<int>& L, int start, int end) {
        int middle = (start+end)/2, pointA = start, pointB = middle + 1, j = pointB, invCounter = 0;
        vector<int> sortedArray;

        /*
            Pela definição do exercício, um par invertido é dado por:
            - 0 <= i < j < L.length()
            - L[i] > 2 * L[j]

            A primeira condição já é validada pela natureza do algoritmo
            divide and conquer, haja vista que o lado direito do vetor sempre
            terá indices maiores que o lado direito.

            Logo, o laço abaixo é feito apenas para validar a segunda condição.
            Primeiramente, enquanto o valor do lado esquerdo do vetor for maior
            que 2x o lado esquerdo, o ponteiro para o lado esquerdo é movimentado.

            Quando essa condição não for mais válida, soma-se a quantidade de números
            onde essa condição foi válida.

            Como ambos os lados estão ordenados (localmente), se um número do lado
            direito é maior que 2x o valor do lado esquerdo, ele será maior que
            todos os valores anteriores do lado esquerdo tbm, daí é válida a soma
            da quantidade de números à esquerda que já passaram.
        */
        for ( auto i = start; i <= middle; ++i ) {
            while ( j <= end && L[i] > 2 * (long long) L[j] ) ++j;
            invCounter += j - pointB;
        }

        // Passando todos os valores de ambos os lados para um vetor ordenadamente
        while ( pointA <= middle && pointB <= end ) {
            if ( L[pointB] < L[pointA] ) {
                sortedArray.push_back(L[pointB++]);
            } else if ( L[pointA] < L[pointB] ) {
                sortedArray.push_back(L[pointA++]);
            } else {
                sortedArray.push_back(L[pointA++]);
                sortedArray.push_back(L[pointB++]);
            }
        }

        // Passando os valores restantes para o vetor ordenado, se houver
        for ( auto i = pointA; i <= middle; ++i ) sortedArray.push_back(L[i]);
        for ( auto i = pointB; i <= end; ++i ) sortedArray.push_back(L[i]);

        // Passando o vetor ordenado para o vetor inicial recebido
        for ( auto i = start; i <= end; ++i ) L[i] = sortedArray[i - start];

        // O retorno é a quantidade de inversões
        return invCounter;
    }

    // Método para dividir o vetor recursivamente e ir somando a qtd de inversões
    int divideAndSum(vector<int>& L, int start, int end) {
        if ( start >= end ) return 0;
        int middle = (start + end) / 2;

        int cA = divideAndSum(L, start, middle);
        int cB = divideAndSum(L, middle + 1, end);
        int r = mergeAndCountInversions(L, start, end);

        return cA + cB + r;
    }

    /*
        Método principal que recebe um vetor de números
        e deve retornar a quantidade de inversões, de acordo
        com a definição de inversão dada pelo exercício
    */
    int reversePairs(vector<int>& nums) {
        return divideAndSum(nums, 0, nums.size() - 1);
    }
};
```
