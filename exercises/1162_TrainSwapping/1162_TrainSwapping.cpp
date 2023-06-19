#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, vector<int>>;

ii mergeAndCount(vector<int> A, vector<int> B) {
    int count = 0, pointA = 0, pointB = 0;
    int tamA = A.size(), tamB = B.size();
    vector<int> sorted;

    while ( pointA < tamA && pointB < tamB ) {
        if ( B[pointB] < A[pointA] ) {
            count += tamA - pointA;
            sorted.push_back(B[pointB]);
            ++pointB;
        } else if ( A[pointA] < B[pointB] ) {
            sorted.push_back(A[pointA]);
            ++pointA;
        } else {
            sorted.push_back(A[pointA]);
            sorted.push_back(B[pointB]);
            ++pointA;
            ++pointB;
        }
    }

    for ( auto i = pointA; i < tamA; ++i ) sorted.push_back(A[i]);
    for ( auto i = pointB; i < tamB; ++i ) sorted.push_back(B[i]);

    return make_pair(count, sorted);
}

ii inversionCount(vector<int> L) {
    int tam = L.size();

    if ( tam == 1 ) return make_pair(0, L);

    vector<int> A;
    vector<int> B;
    int meio = ( tam % 2 == 0 ? (tam / 2) - 1 : tam / 2);
    for ( auto i = 0; i < tam; ++i ) {
        if (i <= meio) A.push_back(L[i]);
        else B.push_back(L[i]);
    }
    
    ii rA = inversionCount(A);
    ii rB = inversionCount(B);
    ii r = mergeAndCount(rA.second, rB.second);

    return make_pair(rA.first + rB.first + r.first, r.second);
}

int main() {
    int N, size, entry;
    vector<int> L;

    cin >> N;

    for ( auto i = 0; i < N; ++i ) {
        cin >> size;

        for ( auto j = 0; j < size; ++j ) {
            cin >> entry;
            L.push_back(entry);
        }

        ii counter = inversionCount(L);
        cout << "Optimal train swapping takes " << counter.first << " swaps." << endl;
    
        L.clear();
    }

    return 0;
}