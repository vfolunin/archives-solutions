#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

bool isSquare(int n) {
    int r = sqrt(n);
    return r * r == n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> row = { 1 };

    for (int i = 1; 1; i++) {
        if (isSquare(digitSum(i * i)))
            row.push_back(row.back() + 1);
        else
            row.push_back(0);

        if (i > 15 && row.back() == 7) {
            for (int j = i - 6; j <= i; j++)
                cout << j << " " << j * j << "\n";
            break;
        }
    }
}