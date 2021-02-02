#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

bool solve() {
    string word;
    if (!(cin >> word))
        return 0;

    int sum = 0;
    for (char c : word) {
        if (islower(c))
            sum += c - 'a' + 1;
        else
            sum += c - 'A' + 27;
    }

    if (isPrime(sum))
        cout << "It is a prime word.\n";
    else
        cout << "It is not a prime word.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}