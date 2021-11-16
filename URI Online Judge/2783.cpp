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

    int n, n1, n2;
    cin >> n >> n1 >> n2;

    set<int> s1;
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        s1.insert(x);
    }

    set<int> s2;
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        s2.insert(x);
    }

    int res = 0;
    for (int x : s1)
        res += !s2.count(x);

    cout << res << "\n";
}