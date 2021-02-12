#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> r >> l;
        s.insert(r - l);
    }
    
    if (test)
        cout << "\n";
    cout << (s.size() == 1 ? "yes\n" : "no\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}