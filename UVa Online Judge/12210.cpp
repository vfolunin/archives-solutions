#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int aSize, bSize;
    cin >> aSize >> bSize;

    if (!aSize && !bSize)
        return 0;

    int minA = 1e9;
    for (int i = 0; i < aSize; i++) {
        int x;
        cin >> x;
        minA = min(minA, x);
    }

    for (int i = 0; i < bSize; i++) {
        int x;
        cin >> x;
    }

    cout << "Case " << test << ": ";
    if (aSize <= bSize)
        cout << "0\n";
    else
        cout << aSize - bSize << " " << minA << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}