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

    for (int a = 999; a >= 100; a--) {
        for (int b = 100; b <= 999; b++) {
            string cur = "0";
            cur += to_string((a % 10) + (b % 10));
            cur += to_string((a / 100 % 10) + (b / 100 % 10));
            cur += to_string((a / 10 % 10) + (b / 10 % 10));

            if (s == cur.substr(cur.size() - 4, 3)) {
                cout << a;
                return 0;
            }
        }
    }
}