#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, vector<int> &used, vector<int> &v) {
    static const vector<int> isPrime = {
        0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 1
    };

    if (v.size() == n) {
        if (isPrime[v.back() + 1])
            for (int i = 0; i < n; i++)
                cout << v[i] << (i + 1 < n ? ' ' : '\n');
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i] && isPrime[v.back() + i]) {
            used[i] = 1;
            v.push_back(i);
            rec(n, used, v);
            used[i] = 0;
            v.pop_back();
        }
    }
}

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> used(n + 1);
    used[1] = 1;
    vector<int> v = { 1 };

    if (test > 1)
        cout << "\n";
    cout << "Case " << test << ":\n";
    rec(n, used, v);
    
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    
    for (int test = 1; solve(test); test++);        
}