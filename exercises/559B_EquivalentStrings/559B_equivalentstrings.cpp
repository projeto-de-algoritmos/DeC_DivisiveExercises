#include <bits/stdc++.h>

using namespace std;

string solve(const string& s) {
    string temp1, temp2;

    if (s.size() & 1) 
    {
        return s;
    }

    int mid = s.size() / 2;

    temp1 = solve(s.substr(0, mid));
    temp2 = solve(s.substr(mid));

    string sum = (temp1<temp2) ? (temp1+temp2): (temp2+temp1);

    return sum;
}

int main() {
    string a, b;

    cin >> a;
    cin >> b;

    string result = (solve(a) == solve(b)) ? "YES" : "NO";

    cout << result << endl;

    return 0;
}

