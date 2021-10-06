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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        bool isPrime = p > 1;
        for (int d = 2; isPrime && d * d <= p; d++)
            isPrime &= p % d != 0;

        cout << p << (isPrime ? "" : " nao") << " eh primo\n";
    }
}