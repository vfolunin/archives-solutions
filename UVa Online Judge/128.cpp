#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    getline(cin, line);

    if (line[0] == '#')
        return 0;

    static const int mod = 34943;
    int sum = 0;
    for (char c : line)
        sum = (sum * 256 + c) % mod;
    
    sum = (sum * 256) % mod;
    sum = (sum * 256) % mod;
    int res = (mod - sum % mod) % mod;

    printf("%02X %02X\n", res / 256, res % 256);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}