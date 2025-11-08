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

    int a, b, c, limit;
    cin >> a >> b >> c >> limit;

    int ways = 0;
    for (int ka = 0; ka * a <= limit; ka++) {
        for (int kb = 0; ka * a + kb * b <= limit; kb++) {
            for (int kc = 0; ka * a + kb * b + kc * c <= limit; kc++) {
                if (ka || kb || kc) {
                    cout << ka << " Brown Trout, " << kb << " Northern Pike, " << kc << " Yellow Pickerel\n";
                    ways++;
                }
            }
        }
    }

    cout << "Number of ways to catch fish: " << ways << "\n";
}