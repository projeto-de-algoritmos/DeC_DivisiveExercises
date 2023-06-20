# Exercício 4 do LeetCode: Median of Two Sorted Arrays

[**Link do Problema**](https://leetcode.com/problems/median-of-two-sorted-arrays/)

## Código comentado

```
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        // Copia os elementos da primeira metade para o vetor da esquerda (leftArr)
        for (int i = 0; i < n1; i++) 
        {
            leftArr[i] = arr[left + i];
        }

        // Copia os elementos da segunda metade para o vetor da direita (rightArr)
        for (int j = 0; j < n2; j++) 
        {
            rightArr[j] = arr[mid + 1 + j];
        }

        int i = 0; 
        int j = 0; 
        int k = left; 

        // Mescla os elementos ordenadamente
        while (i < n1 && j < n2) 
        {
            if (leftArr[i] <= rightArr[j]) 
            {
                arr[k] = leftArr[i];
                i++;
            } 
            else 
            {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Copia os elementos restantes do vetor da esquerda, se houver
        while (i < n1) 
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Copia os elementos restantes do vetor da direita, se houver
        while (j < n2) 
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void mergeSort(std::vector<int>& arr, int left, int right) {
        if (left < right) 
        {
            int mid = left + (right - left) / 2;

            // Ordena recursivamente a primeira metade do vetor
            mergeSort(arr, left, mid);

            // Ordena recursivamente a segunda metade do vetor
            mergeSort(arr, mid + 1, right);

            // Faz o merge das duas metades ordenadas
            merge(arr, left, mid, right);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vtr;

        //passa os valores de nums1 para o vetor principal
        for (auto i : nums1)
        {
            vtr.push_back(i);
        }

        //passa os valores de nums2 para o vetor principal
        for (auto j : nums2)
        {
            vtr.push_back(j);
        }

        //passa o vetor principal para o algoritmo do mergeSort a fim de ordena os valores usando um algoritmo de dividir e conquistar
        mergeSort(vtr, 0, vtr.size() - 1);
        
        int tam = vtr.size();

        /*if (tam % 2 == 1)
        {
            result = vtr[tam/2];
        }
        else
        {
            result = (vtr[tam/2-1]+vtr[tam/2])/2.0;
        }*/
        double result = tam % 2 ? vtr[tam/2] : (vtr[tam/2-1]+vtr[tam/2])/2.0;

        return result;
    }
};
```
