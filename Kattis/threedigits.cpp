#include <iostream>
#include <iomanip>
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

    int count2 = 0, count5 = 0;
    long long res = 1;

    for (int i = 1; i <= n; i++) {
        int value = i;
        for ( ; value % 2 == 0; value /= 2)
            count2++;
        for ( ; value % 5 == 0; value /= 5)
            count5++;
        res = res * value % 1000;
    }

    for (int i = count5; i < count2; i++)
        res = res * 2 % 1000;

    if (n < 7)
        cout << res;
    else
        cout << setw(3) << setfill('0') << res;
}