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

    long long a, b, sum;
    cin >> a >> b >> sum;

    if (a > b)
        swap(a, b);

    long long resKA = 1e18, resKB = 1e18;
    for (int kb = 0; kb * b <= sum; kb++) {
        if ((sum - kb * b) % a)
            continue;

        int ka = (sum - kb * b) / a;
        
        if (resKA + resKB > ka + kb) {
            resKA = ka;
            resKB = kb;
        }
    }

    if (resKA != 1e18)
        cout << resKA << " " << resKB << " " << resKA + resKB;
    else
        cout << -1;
}