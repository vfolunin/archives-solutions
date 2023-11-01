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

    int n, nab, nbc, nac;
    cin >> n >> nab >> nbc >> nac;

    for (int a = 0; a <= 1000; a++) {
        for (int b = 0; b <= 1000; b++) {
            int ab = nab - a - b;
            int c = nab + nbc + nac - n - a - b;
            int bc = nbc - b - c;
            int ac = nac - a - c;

            if (ab >= 0 && c >= 0 && bc >= 0 && ac >= 0) {
                cout << "YES\n" << a << " " << ab << " " << b << " " << bc << " " << c << " " << ac;
                return 0;
            }
        }
    }

    cout << "NO";
}