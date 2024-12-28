#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [](int lhs, int rhs) {
        return sin(lhs) < sin(rhs);
    });

    for (int value : a)
        cout << value << " ";
}