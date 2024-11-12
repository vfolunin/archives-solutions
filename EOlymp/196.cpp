#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

vector<int> prepare() {
    vector<int> grundy(101);

    for (int i = 1; i < grundy.size(); i++) {
        set<int> toGrundy;
        for (int j = 1; j < i; j++)
            if (isPrime(j))
                toGrundy.insert(grundy[i - j]);

        while (toGrundy.count(grundy[i]))
            grundy[i]++;
    }

    return grundy;
}

void solve() {
    static vector<int> grundy = prepare();

    int res = 0;
    do {
        int value;
        cin >> value;

        res ^= grundy[value];
    } while (cin.peek() == ' ');

    cout << (bool)res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}