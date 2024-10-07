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

    int res = 1;
    for (int digit = 2; 1; digit++) {
        int i = s.find(digit + '0');
        if (i == -1)
            break;
        i--;

        if (s[i] == '+')
            res += digit;
        else if (s[i] == '-')
            res -= digit;
        else
            res *= digit;
    }

    cout << res;
}