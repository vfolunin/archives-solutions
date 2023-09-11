#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int n, string &s) {
    int a = n / 1000 + n / 100 % 10;
    int b = n / 10 % 10 + n % 10;

    if (a < b)
        swap(a, b);

    return to_string(a) + to_string(b) == s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int i = 9999; i >= 1000; i--) {
        if (isGood(i, s)) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
}