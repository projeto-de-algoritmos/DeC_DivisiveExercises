# Exercício 559B do CodeForces: Equivalent Strings

[**Link do Problema**](https://codeforces.com/problemset/problem/559/B)

## Código comentado

```
#include <bits/stdc++.h>

using namespace std;

string solve(const string& s) {
    string temp1, temp2;

    if (s.size() & 1) 
    {
        return s;
    }

    int mid = s.size() / 2;

    //Separa as duas strings e resolve cada uma chamando a funcao recursivamente (Dividir e conquistar)
    temp1 = solve(s.substr(0, mid));
    temp2 = solve(s.substr(mid));

    // Caso temp1 < temp2 retorna temp1+temp2, caso não retorna temp2+temp1
    string sum = (temp1<temp2) ? (temp1+temp2): (temp2+temp1);

    return sum;
}

int main() {
    string a, b;

    //Recebe as duas strings
    cin >> a;
    cin >> b;

    //Caso solve(a) == solve(b) print YES, caso não for print NO
    string result = (solve(a) == solve(b)) ? "YES" : "NO";

    cout << result << endl;

    return 0;
}
```