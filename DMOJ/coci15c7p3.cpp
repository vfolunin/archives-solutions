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

    vector<long long> p(size + 1);
    for (int i = 0; i < size; i++) {
        cin >> p[i];
        if (i)
            p[i] ^= p[i - 1];
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long l, r;
        cin >> l >> r;
        l = (l - 1) % (size + 1);
        r = (r - 1) % (size + 1);

        cout << (p[r] ^ (l ? p[l - 1] : 0)) << "\n";
    }
}