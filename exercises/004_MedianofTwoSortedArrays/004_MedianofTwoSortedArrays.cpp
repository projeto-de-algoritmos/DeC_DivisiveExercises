#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        for (int i = 0; i < n1; i++) 
        {
            leftArr[i] = arr[left + i];
        }

        for (int j = 0; j < n2; j++) 
        {
            rightArr[j] = arr[mid + 1 + j];
        }

        int i = 0; 
        int j = 0; 
        int k = left; 

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

        while (i < n1) 
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

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

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vtr;

        
        for (auto i : nums1)
        {
            vtr.push_back(i);
        }

        for (auto j : nums2)
        {
            vtr.push_back(j);
        }

        mergeSort(vtr, 0, vtr.size() - 1);
        
        int tam = vtr.size();

        double result = tam % 2 ? vtr[tam/2] : (vtr[tam/2-1]+vtr[tam/2])/2.0;

        return result;
    }
};