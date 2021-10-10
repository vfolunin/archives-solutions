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

    int lNum = 0, lDen = 1;
    int rNum = 1, rDen = 0;

    while (1) {
        int mNum = lNum + rNum;
        int mDen = lDen + rDen;

        if (num == mNum && den == mDen)
            break;

        if (1LL * num * mDen < 1LL * mNum * den) {
            cout << "L";
            rNum = mNum;
            rDen = mDen;
        } else {
            cout << "R";
            lNum = mNum;
            lDen = mDen;
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