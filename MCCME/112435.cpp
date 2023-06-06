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

    vector<int> count(26);
    for (char c; cin >> c; ) {
        if (c == '.')
            break;
        count[c - 'A']++;
    }

    int odd = -1;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] % 2) {
            if (odd == -1) {
                odd = i;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    string res;
    for (int i = 0; i < count.size(); i++)
        res += string(count[i] / 2, i + 'A');

    cout << "YES\n";
    cout << res;
    if (odd != -1)
        cout << (char)(odd + 'A');
    cout << string(res.rbegin(), res.rend());
}