#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;

    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    reverse(a.begin() + l1 - 1, a.begin() + r1);
    reverse(a.begin() + l2 - 1, a.begin() + r2);

    for (int value : a)
        cout << value << " ";
}