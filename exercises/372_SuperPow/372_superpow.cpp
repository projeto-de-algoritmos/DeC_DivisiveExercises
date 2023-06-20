#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int powMod(int a, int b, int mod) {
        int result = 1;
        a %= mod;
        
        while (b > 0) 
        {
            if (b & 1) 
            {
                result = (result * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1;
        }
        
        return result;
    }

    int superPow(int a, vector<int>& b) {

        if (b.empty()) 
        {
            return 1;
        }
        
        int lastDigit = b.back();
        b.pop_back();

        int part1 = powMod(a, lastDigit, 1337);
        int part2 = powMod(superPow(a, b), 10, 1337);
        
        return (part1 * part2) % 1337;
    }
};