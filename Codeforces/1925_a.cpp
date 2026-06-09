#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, alphabetSize;
    cin >> size >> alphabetSize;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < alphabetSize; j++)
            cout << (char)('a' + j);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}