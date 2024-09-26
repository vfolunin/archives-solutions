#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n) {
    cout << "{";
    for (int i = 0; i < n; i++) {
        rec(i);
        if (i + 1 < n)
            cout << ",";
    }
    cout << "}";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    rec(n);
}