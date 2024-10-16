#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <valarray>
using namespace std;

void solve() {
    string sa, sb;
    int index;
    cin >> sa >> sb >> index;

    vector<valarray<long long>> count(2, valarray<long long>(26));
    for (char c : sa)
        count[0][c - 'a']++;
    for (char c : sb)
        count[1][c - 'a']++;

    for (int i = 2; i <= index; i++)
        count.push_back(count[i - 2] + count[i - 1]);

    for (int i = 0; i < count[index].size(); i++)
        cout << (char)('a' + i) << ":" << count[index][i] << "\n";
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