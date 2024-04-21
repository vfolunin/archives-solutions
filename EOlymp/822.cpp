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

    string res;

    while (1) {
        int len = 1;
        if (isdigit(cin.peek()))
            cin >> len;

        char c;
        if (!(cin >> c))
            break;

        res += string(len, c);
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i % 40 == 39)
            cout << "\n";
    }
}