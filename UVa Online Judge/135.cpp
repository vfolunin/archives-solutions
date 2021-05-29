#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    int rows = n * n - n + 1;

    if (test)
        cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << 1;
        for (int j = 1; j < n; j++)
            cout << " " << (n - 1) * i + j + 1;
        cout << "\n";
    }

    for (int i = n; i < rows; i++) {
        cout << (i - n) / (n - 1) + 2;
        for (int j = 1; j < n; j++) {
            int l = n + 1 + (j - 1) * (n - 1);
            int si = (i - n) % (n - 1);
            int sj = j - 1;
            int sk = (i - n) / (n - 1);
            int s = (si + sj * sk) % (n - 1);
            cout << " " << l + s;
        }
        cout << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}