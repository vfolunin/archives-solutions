#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    unordered_set<int> values;

    long long prev = 0;
    const long long MOD = 1e9;

    for (int i = 0; i < opCount; i++) {
        char type;
        cin >> type;

        if (type == '+') {
            int value;
            cin >> value;

            values.insert((value + prev) % MOD);
            prev = 0;
        } else {
            int l, r;
            cin >> l >> r;

            prev = 0;
            for (int value : values)
                if (l <= value && value <= r)
                    prev += value;

            cout << prev << "\n";
        }
    }
}