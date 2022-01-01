#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> fib = { 0, 1 };
    for (int i = 2; 1; i++) {
        fib.push_back((fib[i - 1] + fib[i - 2]) % 1000);
        if (fib[fib.size() - 2] == 0 && fib[fib.size() - 1] == 1)
            break;
    }
    fib.pop_back();
    fib.pop_back();
    return fib;
}

void solve() {
    string bin;
    cin >> bin;

    static vector<int> fib = prepare();

    int num = 0;
    for (char bit : bin)
        num = (num * 2 + bit - '0') % fib.size();

    cout << setw(3) << setfill('0') << fib[num] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}