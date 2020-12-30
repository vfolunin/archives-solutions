#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    cout << "Case " << test << ": " << (int)v.size() - 2 * count(v.begin(), v.end(), 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}