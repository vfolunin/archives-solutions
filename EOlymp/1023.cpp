#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b, vector<int> &v) {
    if (!b)
        return a;
    v.push_back(a / b);
    return gcd(b, a % b, v);
}

bool solve() {
    int a, b;
    if (!(cin >> a >> b))
        return 0;

    vector<int> v;
    gcd(a, b, v);

    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size())
            cout << (i ? "," : ";");
        else
            cout << "]\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}