#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
using namespace std;

char getSign(vector<int> &a, int index, int targetSum) {
    bitset<80001> can;
    int offset = 40000;
    can[offset] = 1;

    for (int i = 0; i < a.size(); i++)
        if (i != index)
            can = (can << a[i]) | (can >> a[i]);
    
    if (can[targetSum + offset - a[index]] && can[targetSum + offset + a[index]])
        return '?';
    if (can[targetSum + offset - a[index]])
        return '+';
    if (can[targetSum + offset + a[index]])
        return '-';
    return '*';
}

bool solve() {
    int n, targetSum;
    cin >> n >> targetSum;

    if (!n && !targetSum)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    string res;
    for (int i = 0; i < n; i++) {
        res += getSign(a, i, targetSum);
        if (res == "*")
            break;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}