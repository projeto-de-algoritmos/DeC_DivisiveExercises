# Exercício 932 do LeetCode: Beautiful Array

[**Link do Problema**](https://leetcode.com/problems/super-pow/)

## Código comentado

```
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //Implemetacao interativa da exponenciacao rápida (Usados em Competitive Programming) 
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
        
        //Remove o último valor do vetor
        int lastDigit = b.back();
        b.pop_back();

        // Calcula a primeira parte da super exponenciação
        int part1 = powMod(a, lastDigit, 1337);

        // Calcula parcialmente os resultados e, em seguida, combinando-os para obter o resultado final. Utiliza recursao
        // Calcula a segunda parte da super exponenciação através de recursão
        int part2 = powMod(superPow(a, b), 10, 1337);
        
        // Retorna o resultado final da super exponenciação
        return (part1 * part2) % 1337;
    }
};
```