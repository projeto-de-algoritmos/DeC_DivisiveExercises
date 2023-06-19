#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, int>;

class Solution {
public:
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
            qsort(&sortedNumsGroups[i][0], tamanho, sizeof(int), compare);

            int posi = tamanho/2;
            mediansGroup.push_back(sortedNumsGroups[i][posi]);
        }

        int tam = mediansGroup.size();

        if (tam <= 5) {
            int pos = tam/2;
            return mediansGroup[pos];
        }

        return medianOfMedians(mediansGroup);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int mom = medianOfMedians(nums);

        vector<int> L;
        vector<int> equal;
        vector<int> R;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < mom) L.push_back(nums[i]);
            else if (nums[i] > mom) R.push_back(nums[i]);
            else equal.push_back(nums[i]);
        }

        int tam = R.size();
        if (tam >= k) mom = findKthLargest(R, k);
        else if (k > tam + equal.size()) mom = findKthLargest(L, k - tam - equal.size());

        return mom;
    }
};