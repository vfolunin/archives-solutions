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

    int size;
    cin >> size;

    string s(size, 'A');
    for (int i = 0; i < size; i++)
        s[i] += i;

    string res;
    for (int l = 0, r = s.size() - 1; l <= r; l++, r--) {
        if (s.size() % 2) {
            res += s[r];
            if (l != r)
                res += s[l];
        } else {
            res += s[l];
            res += s[r];
        }
    }
    reverse(res.begin(), res.end());

    cout << res;
}