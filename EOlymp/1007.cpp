#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int num, den;
    cin >> num >> den;

    if (num == 1 && den == 1)
        return 0;

    int lNum = 0, lDen = 1, rNum = 1, rDen = 0;
    while (1) {
        int mNum = lNum + rNum, mDen = lDen + rDen;
        if (mNum * den == num * mDen) {
            break;
        } else if (mNum * den < num * mDen) {
            lNum = mNum;
            lDen = mDen;
            cout << "R";
        } else {
            rNum = mNum;
            rDen = mDen;
            cout << "L";
        }
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}