#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int p3(int n) {
    return n * n * n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> res;

    const int LIMIT = p3(200);
    for (int a = 2; p3(a) <= LIMIT; a++) {
        for (int b = a; p3(a) + p3(b) <= LIMIT; b++) {
            for (int c = b; p3(a) + p3(b) + p3(c) <= LIMIT; c++) {

                int x = p3(a) + p3(b) + p3(c);

                int l = 0, r = 200;
                while (l + 1 < r) {
                    int m = (l + r) / 2;
                    if (p3(m) < x)
                        l = m;
                    else
                        r = m;
                }

                if (p3(r) == x)
                    res.push_back({ r, a, b, c });

            }
        }
    }

    sort(res.begin(), res.end());

    for (auto &r : res)
        cout << "Cube = " << r[0] << ", Triple = (" << r[1] << "," << r[2] << "," << r[3] << ")\n";
}