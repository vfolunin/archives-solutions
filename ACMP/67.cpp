#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

unsigned int readIp() {
    unsigned int res = 0;

    for (int i = 0; i < 4; i++) {
        int part;
        cin >> part;
        if (i < 3)
            cin.ignore();
        res = (res << 8) | part;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int maskCount;
    cin >> maskCount;

    vector<unsigned int> masks(maskCount);
    for (unsigned int &mask : masks)
        mask = readIp();

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        unsigned int addressA = readIp();
        unsigned int addressB = readIp();

        int res = 0;
        for (unsigned int mask : masks)
            res += (addressA & mask) == (addressB & mask);

        cout << res << "\n";
    }
}