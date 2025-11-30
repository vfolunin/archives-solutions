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

    int size;
    cin >> size;

    const int MOD = 998244353;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum = (sum + value) % MOD;
    }

    cout << sum;
}