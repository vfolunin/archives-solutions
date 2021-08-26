#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getCatalan() {
    vector<long long> catalan(21);
    catalan[0] = 1;
    for (int n = 1; n < 21; n++)
        for (int i = 0; i < n; i++)
            catalan[n] += catalan[i] * catalan[n - 1 - i];
    return catalan;
}

string getNth(int len, long long n) {
    static vector<long long> count = getCatalan();

    if (n >= count[len])
        return "ERROR";

    if (!len)
        return "";
    
    int tailLen = 0;
    while (n >= count[tailLen] * count[len - 1 - tailLen]) {
        n -= count[tailLen] * count[len - 1 - tailLen];
        tailLen++;
    }

    return "E" + getNth(len - 1 - tailLen, n / count[tailLen]) + "S" + getNth(tailLen, n % count[tailLen]);
}

bool solve() {
    int bracketCount;
    long long n;
    cin >> bracketCount >> n;

    if (!bracketCount)
        return 0;

    cout << getNth(bracketCount - 1, n - 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}