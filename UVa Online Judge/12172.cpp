#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> prepare() {
    static vector<int> matchCount = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    vector<string> res(30);

    for (int i = 1; i < 1000; i++) {
        int sum = 0;
        for (char c : to_string(i))
            sum += matchCount[c - '0'];

        if (res[sum].empty())
            res[sum] = to_string(i);
    }

    return res;
}

string l(int n) {
    string eights;
    while (n > 21) {
        n -= 7;
        eights += "8";
    }

    static vector<string> res = prepare();
    return res[n] + eights;
}

string r(int n) {
    return (n % 2 ? "7" : "1") + string((n - 2) / 2, '1');
}

void solve() {
    int n;
    cin >> n;

    cout << l(n) << " " << r(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}