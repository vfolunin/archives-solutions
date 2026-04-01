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

    int volume;
    cin >> volume;

    int res = 1e9;
    for (int a = 1; a * a * a <= volume; a++) {
        for (int b = a; a * b * b <= volume; b++) {
            if (volume % (a * b) == 0) {
                int c = volume / (a * b);
                res = min(res, 2 * (a * b + a * c + b * c));
            }
        }
    }

    cout << res;
}