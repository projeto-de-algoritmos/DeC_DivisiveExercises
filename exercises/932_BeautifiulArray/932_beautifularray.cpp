#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:

    vector<int> beautifulArray(int n) {
        if (n == 1) 
        {
            return {1};
        }

        vector<int> leftArr = beautifulArray((n + 1) / 2); 
        vector<int> rightArr = beautifulArray(n / 2); 

        vector<int> result;
        
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
