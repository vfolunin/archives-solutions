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

    int n, sub, add;
    cin >> sub >> n >> add;

    if (n <= sub)
        cout << 1;
    else if (add < sub)
        cout << (n - sub + sub - add - 1) / (sub - add) + 1;
    else
        cout << "NO";
}