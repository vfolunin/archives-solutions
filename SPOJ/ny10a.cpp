#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test;
    string tosses;
    cin >> test >> tosses;

    for (char &toss : tosses)
        toss = toss == 'H';

    vector<int> res(8);
    for (int i = 0; i + 3 <= tosses.size(); i++)
        res[tosses[i] * 4 + tosses[i + 1] * 2 + tosses[i + 2]]++;

    cout << test;
    for (int x : res)
        cout << " " << x;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}