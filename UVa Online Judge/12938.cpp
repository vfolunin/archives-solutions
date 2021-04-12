#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isSquare(int n) {
    int r = sqrt(n);
    return r * r == n;
}

void solve(int test) {
    string number;
    cin >> number;

    int squareCount = 0;
    for (int pos = 0; pos < 4; pos++) {
        char prevDigit = number[pos];
        for (number[pos] = '0' + !pos; number[pos] <= '9'; number[pos]++)
            if (number[pos] != prevDigit && isSquare(stoi(number)))
                squareCount++;
        number[pos] = prevDigit;
    }

    cout << "Case " << test << ": " << squareCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}