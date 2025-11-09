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

    int a, b, c, d, sum;
    cin >> a >> b >> c >> d >> sum;

    int ways = 0, minK = 1e9;
    for (int ka = 0; ka * a <= sum; ka++) {
        for (int kb = 0; ka * a + kb * b <= sum; kb++) {
            for (int kc = 0; ka * a + kb * b + kc * c <= sum; kc++) {
                int kd = (sum - ka * a - kb * b - kc * c) / d;

                if (ka * a + kb * b + kc * c + kd * d == sum) {
                    cout << "# of PINK is " << ka << " # of GREEN is " << kb << " # of RED is " << kc << " # of ORANGE is " << kd << "\n";
                    ways++;
                    minK = min(minK, ka + kb + kc + kd);
                }
            }
        }
    }

    cout << "Total combinations is " << ways << ".\n";
    cout << "Minimum number of tickets to print is " << minK << ".\n";
}