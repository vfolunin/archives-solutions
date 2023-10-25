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

    string a, b;
    getline(cin, a);
    getline(cin, b);

    map<char, char> ab, ba;

    for (int i = 0; i < a.size(); i++) {
        if (!ab.count(a[i]) && !ba.count(b[i])) {
            ab[a[i]] = b[i];
            ba[b[i]] = a[i];
        } else if (ab[a[i]] != b[i] || ba[b[i]] != a[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}