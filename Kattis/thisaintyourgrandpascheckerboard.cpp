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

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    for (int y = 0; y < size; y++) {
        int countB = 0, countW = 0, curB = 0, curW = 0, maxB = 0, maxW = 0; 
        for (int x = 0; x < size; x++) {
            if (a[y][x] == 'B') {
                countB++;
                curB++;
                curW = 0;
            } else {
                countW++;
                curW++;
                curB = 0;
            }
            maxB = max(maxB, curB);
            maxW = max(maxW, curW);
        }

        if (countB != countW || maxB >= 3 || maxW >= 3) {
            cout << 0;
            return 0;
        }
    }

    for (int x = 0; x < size; x++) {
        int countB = 0, countW = 0, curB = 0, curW = 0, maxB = 0, maxW = 0;
        for (int y = 0; y < size; y++) {
            if (a[y][x] == 'B') {
                countB++;
                curB++;
                curW = 0;
            } else {
                countW++;
                curW++;
                curB = 0;
            }
            maxB = max(maxB, curB);
            maxW = max(maxW, curW);
        }

        if (countB != countW || maxB >= 3 || maxW >= 3) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}