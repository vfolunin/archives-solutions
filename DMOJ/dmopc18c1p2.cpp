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

    int size, mod;
    cin >> size >> mod;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if ((value - 1) % mod != i % mod) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}