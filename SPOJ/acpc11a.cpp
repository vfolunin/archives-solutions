#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    int index = find_if(a.begin(), a.end(), [](string &s) {
        return s[0] != '#';
    }) - a.begin();

    for (int i = index + 1; i < a.size(); i++)
        cout << a[i] << " ";
    if (index < a.size())
        cout << a[index] << " ";
    for (int i = 0; i < index; i++)
        cout << a[i] << " ";
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