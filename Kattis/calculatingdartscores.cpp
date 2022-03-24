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

    int score;
    cin >> score;

    vector<string> multiplier = { "", "single", "double", "triple" };
    for (int a = 1; a <= 20; a++) {
        for (int b = 1; b <= 20; b++) {
            for (int c = 1; c <= 20; c++) {
                for (int ka = 0; ka <= 3; ka++) {
                    for (int kb = 0; kb <= 3; kb++) {
                        for (int kc = 0; kc <= 3; kc++) {
                            if (a * ka + b * kb + c * kc == score) {
                                if (ka)
                                    cout << multiplier[ka] << " " << a << "\n";
                                if (kb)
                                    cout << multiplier[kb] << " " << b << "\n";
                                if (kc)
                                    cout << multiplier[kc] << " " << c << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "impossible";
}