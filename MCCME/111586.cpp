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

    vector<int> factorial(size + 1);
    factorial[0] = 1 % mod;
    for (int i = 1; i < factorial.size(); i++)
        factorial[i] = factorial[i - 1] * i % mod;

    int res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res = (res + factorial[size - i] * value) % mod;
    }

    cout << res;
}