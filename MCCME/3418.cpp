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

    string res;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        if (res.find(s) == -1)
            res += s;
    }

    cout << res;
}