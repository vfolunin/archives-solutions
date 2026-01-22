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

    long long count, limit1, limit3;
    cin >> count >> limit1 >> limit3;

    if (count < 3) {
        cout << limit1 / count;
        return 0;
    }

    long long count3 = count / 3, res = 0;
    if (count3 * 3 == count)
        res = limit3 / count3;
    else
        res = min(limit3 / count3, limit1 / (count - count3 * 3));
    
    limit3 -= res * count3;
    limit1 -= res * (count - count3 * 3);
    res += limit1 / count;

    cout << res;
}