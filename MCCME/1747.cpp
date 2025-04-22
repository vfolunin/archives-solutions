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

    int n;
    cin >> n;

    cout << n * (n + 1) / 2 << "\n";
    for (int to = 1; to <= n; to++)
        for (int i = n; i >= to; i--)
            cout << i << " ";
    cout << 1;
}