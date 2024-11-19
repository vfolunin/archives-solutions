#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, int from, vector<int> &factors) {
    if (n == 1) {
        for (int i = 0; i < factors.size(); i++)
            cout << (i ? "*" : "") << factors[i];
        cout << "\n";
        return;
    }

    for (int d = from; d <= n; d++) {
        if (n % d == 0) {
            factors.push_back(d);
            rec(n / d, d, factors);
            factors.pop_back();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, from;
    cin >> n >> from;

    vector<int> factors;
    rec(n, from, factors);
}