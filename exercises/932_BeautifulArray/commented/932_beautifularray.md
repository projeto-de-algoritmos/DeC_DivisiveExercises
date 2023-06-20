# Exercício 932 do LeetCode: Beautiful Array

[**Link do Problema**](https://leetcode.com/problems/beautiful-array/)

## Código comentado

```
#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:

    vector<int> beautifulArray(int n) {
        //A função verifica se o valor de n é igual a 1. Se for, retorna um vetor contendo o número 1. Isso é o caso base da recursão.
        if (n == 1) 
        {
            return {1};
        }

        //Caso contrário, a função divide o problema em duas partes, chamando a função beautifulArray recursivamente.

        //A parte esquerda (leftArr) é calculada chamando a função beautifulArray passando (n + 1) / 2. Isso lida com números ímpares.
        vector<int> leftArr = beautifulArray((n + 1) / 2); 

        //A parte direita (rightArr) é calculada chamando a função beautifulArray passando n / 2. Isso lida com números pares.
        vector<int> rightArr = beautifulArray(n / 2); 

        //Em seguida, os resultados da parte esquerda e da parte direita são mesclados para formar o array bonito final (result).
        vector<int> result;
        
        //Isso é feito multiplicando cada elemento em leftArr por 2 e subtraindo 1, e multiplicando cada elemento em rightArr por 2.
        for (auto i : leftArr) 
        {
            result.push_back(2 * i - 1);
        }

        for (auto i : rightArr) 
        {
            result.push_back(2 * i);
        }

        return result;

    }
};
```