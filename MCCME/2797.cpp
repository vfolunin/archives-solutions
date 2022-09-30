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
    for (char c : s) {
        if (c == '0' || c == '6' || c == '9')
            res++;
        else if (c == '8')
            res += 2;
    }

    cout << res;
}