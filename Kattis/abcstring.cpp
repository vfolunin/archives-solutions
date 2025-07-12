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

    string s;
    cin >> s;

    vector<int> maskCount(7);

    for (char c : s) {
        int bit = 1 << (c - 'A');

        if (maskCount[7 - bit]) {
            maskCount[7 - bit]--;
            maskCount[0]++;
        } else {
            bool found = 0;

            for (int otherBit : { 1, 2, 4 }) {
                if (otherBit != bit && maskCount[otherBit]) {
                    maskCount[otherBit]--;
                    maskCount[bit | otherBit]++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (maskCount[0])
                    maskCount[0]--;
                maskCount[bit]++;
            }
        }
    }

    cout << maskCount[0];
}