#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << ((a - 1) / 4 == (b - 1) / 4 ? "YES\n" : "NO\n");
    cout << (a % 2 ? "LOW\n" : "HIGH\n");
    cout << (b % 2 ? "LOW\n" : "HIGH\n");
}