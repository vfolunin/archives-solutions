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

    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += stoi(s);
        rotate(s.begin(), s.begin() + 1, s.end());
    }

    cout << res;
}