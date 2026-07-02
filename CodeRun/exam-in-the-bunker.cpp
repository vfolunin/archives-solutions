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

    long long count;
    cin >> count;

    long long res = count;
    for (long long rows = 1; rows * rows <= count * 2; rows++) {
        if (count % rows == 0) {
            long long cols = count / rows;
            res = min(res, abs(rows - cols));
        }

        long long rowsA = rows / 2;
        long long rowsB = rows - rowsA;

        if ((count - rowsA) % rows == 0) {
            long long cols = (count - rowsA) / rows;
            res = min(res, abs(rows - (cols + 1)));
        }
        if ((count - rowsB) % rows == 0) {
            long long cols = (count - rowsB) / rows;
            res = min(res, abs(rows - (cols + 1)));
        }
    }

    cout << res;
}