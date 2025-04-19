#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long num, den, targetNum, targetDen;
    cin >> num >> den >> targetNum >> targetDen;

    for (int i = 0; num * targetDen <= targetNum * den; i++) {
        if (num == targetNum && den == targetDen) {
            cout << i;
            return 0;
        }

        num++;
        den++;
        int d = gcd(num, den);
        num /= d;
        den /= d;
    }

    cout << 0;
}