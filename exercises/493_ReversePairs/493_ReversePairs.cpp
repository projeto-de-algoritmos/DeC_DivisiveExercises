#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, vector<int>>;

class Solution {
public:

    int mergeAndCountInversions(vector<int>& L, int start, int end) {
        int middle = (start+end)/2, pointA = start, pointB = middle + 1, j = pointB, invCounter = 0;
        vector<int> sortedArray;

        for ( auto i = start; i <= middle; ++i ) {
            while ( j <= end && L[i] > 2 * (long long) L[j] ) ++j;
            invCounter += j - pointB;
        }

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

        for ( auto i = pointA; i <= middle; ++i ) sortedArray.push_back(L[i]);
        for ( auto i = pointB; i <= end; ++i ) sortedArray.push_back(L[i]);

        for ( auto i = start; i <= end; ++i ) L[i] = sortedArray[i - start];

        return invCounter;
    }

    int divideAndSum(vector<int>& L, int start, int end) {
        if ( start >= end ) return 0;
        int middle = (start + end) / 2;

        int cA = divideAndSum(L, start, middle);
        int cB = divideAndSum(L, middle + 1, end);
        int r = mergeAndCountInversions(L, start, end);

        return cA + cB + r;
    }

    int reversePairs(vector<int>& nums) {
        return divideAndSum(nums, 0, nums.size() - 1);
    }
};