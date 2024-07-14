#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool matches(int digit, char c) {
    if (isdigit(c))
        return digit == c - '0';
    if (islower(c))
        return c - 'a' <= digit && digit <= c - 'a' + 3;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    int res = 1;
    for (int i = 0; i < a.size(); i++) {
        int count = 0;
        for (int digit = 0; digit < 10; digit++)
            count += matches(digit, a[i]) && matches(digit, b[i]);
        res *= count;
    }

    cout << res;
}