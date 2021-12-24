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
    
    long long n;
    cin >> n;

    int primeDivisorCount = 0;

    for (long long d = 2; d * d <= n; d++) {
        if (n % d)
            continue;
        primeDivisorCount++;
        while (n % d == 0)
            n /= d;
    }
    primeDivisorCount += n > 1;

    cout << (1LL << primeDivisorCount) - primeDivisorCount - 1 << "\n";
}