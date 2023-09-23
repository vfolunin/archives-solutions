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

    vector<long long> count(size + 1);
    count[2] = 1 % mod;

    for (int i = 2; i + 1 < count.size(); i++) {
        count[i + 1] = (count[i + 1] + count[i]) % mod;
        if (i * 2 < count.size())
            count[i * 2] = (count[i * 2] + count[i]) % mod;
    }

    cout << count[size];
}