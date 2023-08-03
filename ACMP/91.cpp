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
    n--;

    vector<int> a = { 2, 3, 4, 7, 13 };
    vector<int> b = { 1, 5, 6, 8, 9, 10, 11, 12 };

    for (int i = 5; i <= n; i++) {
        a.push_back(b[i - 1] + b[i - 3]);

        for (int value = a[i - 1] + 1; value < a[i] && b.size() <= n; value++)
            b.push_back(value);
    }

    cout << a[n] << "\n" << b[n];
}