#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

unsigned int readIp() {
    unsigned int res = 0;

    for (int i = 0; i < 4; i++) {
        int part;
        cin >> part;
        if (i < 3)
            cin.ignore();
        res = (res << 8) | part;
    }

    return res;
}

int ones(unsigned int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

long long c(int n, int k) {
    static vector<vector<long long>> memo(40, vector<long long>(40, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = (c(n - 1, k) + c(n - 1, k - 1));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned int ip = readIp();
    unsigned int mask = readIp();
    
    int divisor;
    cin >> divisor;

    int commonOnes = ones(ip & mask);
    int places = 32 - ones(mask);
    long long res = 0;

    for (int extraOnes = 0; extraOnes <= places; extraOnes++)
        if ((commonOnes + extraOnes) % divisor)
            res += c(places, extraOnes);

    cout << res;
}