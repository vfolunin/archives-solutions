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
    int targetWidth;
    cin >> s >> targetWidth;

    int width = 0, res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!i || s[i - 1] != s[i])
            width = 1;
        else
            width++;
        res += width >= targetWidth;
    }

    cout << res;
}