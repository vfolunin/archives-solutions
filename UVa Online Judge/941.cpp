#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

unsigned long long fact(int n) {
    unsigned long long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

unsigned long long permutationCount(map<char, int> &count) {
    int len = 0;
    for (auto &[_, k] : count)
        len += k;
    unsigned long long res = fact(len);
    for (auto &[_, k] : count)
        res = res / fact(k);
    return res;
}

void solve() {
    string s;
    unsigned long long n;
    cin >> s >> n;

    map<char, int> count;
    for (char c : s)
        count[c]++;

    while (!count.empty()) {
        for (auto &[c, k] : count) {
            k--;
            unsigned long long p = permutationCount(count);
            if (n >= p) {
                n -= p;
            } else {
                cout << c;
                if (!k)
                    count.erase(c);
                break;
            }
            k++;
        }
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}