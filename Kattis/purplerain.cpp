#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> balance = { 0 };
    for (int i = 0; i < s.size(); i++)
        balance.push_back(balance.back() + (s[i] == 'R' ? 1 : -1));
        
    int l = min_element(balance.begin(), balance.end()) - balance.begin();
    int r = max_element(balance.begin(), balance.end()) - balance.begin();
    if (l > r)
        swap(l, r);

    cout << l + 1 << " " << r;
}