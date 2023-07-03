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

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int m = max({ (a + 1) / 2, b, c });
    int da = 2 * m - a, db = m - b, dc = m - c;

    if (n < da + db + dc) {
        cout << 0;
    } else {
        n -= da + db + dc;
        da += n / 4 * 2;
        db += n / 4;
        dc += n / 4;
        cout << da << "\n" << db << "\n" << dc;
    }
}