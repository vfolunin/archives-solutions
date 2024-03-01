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
 
    int n;
    cin >> n;

    int res = n;
    if (!res) {
        cout << res;
        return 0;
    }

    string s;
    while (n) {
        s += '0' + n % 2;
        n /= 2;
    }
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        res = max(res, stoi(s, 0, 2));
    }

    cout << res;
}