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

    int d1, m1, d2, m2;
    cin >> d1 >> m1 >> d2 >> m2;

    vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int res = 0;
    while (d1 != d2 || m1 != m2) {
        res++;
        d1++;
        if (d1 > days[m1]) {
            d1 = 1;
            m1++;
        }
    }

    cout << res << "\n";
}