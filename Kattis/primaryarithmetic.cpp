#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string a, b;
    cin >> a >> b;

    if (a == "0" && b == "0")
        return 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int res = 0, carry = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        int da = i < a.size() ? a[i] - '0' : 0;
        int db = i < b.size() ? b[i] - '0' : 0;
        carry = (da + db + carry) / 10;
        res += carry;
    }

    if (res == 0)
        cout << "No carry operation.\n";
    else if (res == 1)
        cout << "1 carry operation.\n";
    else
        cout << res << " carry operations.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}