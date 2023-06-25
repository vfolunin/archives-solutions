#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, int from, vector<int> &a) {
    if (n == 1) {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 < a.size() ? "*" : "\n");
        return;
    }

    for (int d = from; d <= n; d++) {
        if (n % d == 0) {
            a.push_back(d);
            rec(n / d, d, a);
            a.pop_back();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, from;
    cin >> n >> from;

    vector<int> a;
    rec(n, from, a);
}