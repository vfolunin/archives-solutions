#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int factorA = 1, factorB = 9, sumA = 0, sumB = 0;
    for (int i : {0, 1, 2, 4, 5, 6, 8, 9, 10}) {
        sumA += (s[i] - '0') * factorA++;
        sumB += (s[i] - '0') * factorB--;
    }

    if (s[12] - '0' == sumA % 11 % 10 && s[13] - '0' == sumB % 11 % 10)
        cout << "CPF valido\n";
    else
        cout << "CPF invalido\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}