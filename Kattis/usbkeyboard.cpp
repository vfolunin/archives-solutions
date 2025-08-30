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

    string s;
    cin >> s;

    int row = 1, res = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] >= s[i] || ++row > 6) {
            row = 1;
            res++;
        }
    }

    cout << res;
}