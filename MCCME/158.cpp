#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int sum, vector<int> &a) {
    if (!sum) {
        for (int value : a)
            cout << value << " ";
        exit(0);
    }

    if (a.size() == 8)
        return;

    for (int i = pow(sum, 1 / 3.0); i; i--) {
        a.push_back(i);
        rec(sum - i * i * i, a);
        a.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a;
    rec(n, a);

    cout << "IMPOSSIBLE";
}