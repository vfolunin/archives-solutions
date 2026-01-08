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

    vector<int> a(3);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    string s;
    cin >> s;

    for (char c : s)
        cout << a[c - 'A'] << " ";
}