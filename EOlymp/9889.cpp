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

    if (size > mod) {
        cout << 0;
        return 0;
    }

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 1 % mod;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            res = res * abs(a[i] - a[j]) % mod;

    cout << res;
}