#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int matchCount;
    cin >> matchCount;

    string results;
    cin >> results;

    int b = 0, w = 0, a = 0, t = 0;
    for (char c : results) {
        b += c == 'B';
        w += c == 'W';
        a += c == 'A';
        t += c == 'T';
    }

    cout << "Case " << test << ": ";
    if (a == matchCount)
        cout << "ABANDONED\n";
    else if (b + a == matchCount)
        cout << "BANGLAWASH\n";
    else if (w + a == matchCount)
        cout << "WHITEWASH\n";
    else if (b == w)
        cout << "DRAW " << b << " " << t << "\n";
    else if (b > w)
        cout << "BANGLADESH " << b << " - " << w << "\n";
    else
        cout << "WWW " << w << " - " << b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}