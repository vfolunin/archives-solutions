#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, bool brackets) {
    if (brackets)
        cout << "{";
    
    if (n > 1) {
        rec(n - 1, 0);
        cout << ",";
    }

    if (n > 0)
        rec(n - 1, 1);

    if (brackets)
        cout << "}";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    rec(n, 1);
}