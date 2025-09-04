#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, windowWidth;
    cin >> size >> windowWidth;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    multiset<int> window;
    for (int i = 0; i < windowWidth; i++)
        window.insert(a[i]);
    cout << *window.rbegin() << " ";

    for (int i = windowWidth; i < size; i++) {
        window.erase(window.find(a[i - windowWidth]));
        window.insert(a[i]);
        cout << *window.rbegin() << " ";
    }
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