#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void print(int i) {
    if (i == 1) {
        cout << "((A0|B0)|(A0|B0))";
    } else {
        cout << "((A" << i - 1 << "|B" << i - 1 << ")|(";
        print(i - 1);
        cout << "|((A" << i - 1 << "|A" << i - 1 << ")|(B" << i - 1 << "|B" << i - 1 << "))))";
    }
}

void solve(int test) {
    int n;
    cin >> n;

    if (test)
        cout << "\n";
    print(n);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}