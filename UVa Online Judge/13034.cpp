#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> a(13);
    for (int &x : a)
        cin >> x;

    cout << "Set #" << test << ": ";
    cout << (count(a.begin(), a.end(), 0) ? "No\n" : "Yes\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}