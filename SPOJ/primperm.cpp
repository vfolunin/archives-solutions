#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> prepare() {
    vector<int> isPrime(1e7 + 1, 1);
    unordered_map<string, int> count;

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;

            string s = to_string(i);
            sort(s.begin(), s.end());
            count[s]++;
        }
    }

    return count;
}

void solve() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    static unordered_map<string, int> count = prepare();

    cout << (count.count(s) ? count[s] : 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}