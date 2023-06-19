# Exercício 215 do LeetCode: Kth Largest Element in an Array

[**Link do Problema**](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## Código comentado

```
#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, int>;

class Solution {
public:

    // Função para o cálculo da mediana das medianas
    int medianOfMedians (vector<int> nums) {
        auto compare = [](const void *a, const void *b){
            const int *x = (int*) a;
            const int *y = (int*) b;

            if (*x == *y) return 0;

            return (*x > *y ? 1 : -1);
        };

        int counter = 1, index = 0;
        vector<vector<int>> sortedNumsGroups;
        vector<int> mediansGroup;

        vector<int> intermediateVector;

        // Dividindo os números em grupos de 5
        for (auto element : nums) {
            if (counter > 5) {
                sortedNumsGroups.push_back(intermediateVector);
                intermediateVector.clear();
                counter = 1;
            }

            intermediateVector.push_back(element);
            ++counter;
        }
        if (!intermediateVector.empty()) sortedNumsGroups.push_back(intermediateVector);

        for (auto i = 0; i < sortedNumsGroups.size(); ++i) {
            int tamanho = sortedNumsGroups[i].size();

            // Ordenando os números do subgrupo em questão
            qsort(&sortedNumsGroups[i][0], tamanho, sizeof(int), compare);

            // Selecionando a mediana do subgrupo ordenado
            int posi = tamanho/2;
            mediansGroup.push_back(sortedNumsGroups[i][posi]);
        }

        int tam = mediansGroup.size();

        /*
            Se há 5 ou menos valores no grupo das medianas,
            podemos retornar o valor da mediana das medianas...
        */
        if (tam <= 5) {
            int pos = tam/2;
            return mediansGroup[pos];
        }

        // Caso exista mais de 5 valores, fazemos a chamada recursiva...
        return medianOfMedians(mediansGroup);
    }

    int findKthLargest(vector<int>& nums, int k) {

        // Recebendo a mediana das medianas
        int mom = medianOfMedians(nums);

        vector<int> L;
        vector<int> equal;
        vector<int> R;

        // Separando os valores menores, iguais e maiores que a mediana das medianas
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < mom) L.push_back(nums[i]);
            else if (nums[i] > mom) R.push_back(nums[i]);
            else equal.push_back(nums[i]);
        }

        int tam = R.size();

        /*
            Se o número de elementos maiores que a MoM é 
            maior ou igual do que o valor de k, fazemos a chamada
            recursiva no vetor dos maiores elementos...
        */
        if (tam >= k) mom = findKthLargest(R, k);

        /*
            Se o valor de k é maior que a soma das quantidades
            de números maiores e iguais que a MoM, fazemos a chamada
            recursiva no vetor da esquerda, com o valor de k sendo
            subtraído da soma das quantidades de números maiores e 
            iguais que a MoM
        */
        else if (k > tam + equal.size()) mom = findKthLargest(L, k - tam - equal.size());

        return mom;
    }
};
```
