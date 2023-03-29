#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    unordered_map<int, int> square;
    for (int i = 0; i * i < n; i++)
        square[i * i] = i;

    for (int i = 0; i * i < n; i++) {
        if (square.count(n - i * i)) {
            cout << "YES\n" << i << " " << square[n - i * i];
            return 0;
        }
    }

    cout << "NO";
}