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

    int partCount = 0, partSize = 0, res = 0;
    unsigned int prevPartHash = -1, partHash = 0, mod = 1e9 + 7;

    for (char c : s) {
        if (c == 'A') {
            if (prevPartHash == partHash)
                partCount++;
            else
                partCount = 1;

            if (partCount == 3)
                res = max(res, partSize * 3 + 4);

            prevPartHash = partHash;
            partHash = 0;
            partSize = 0;
        } else {
            partHash = (partHash * 7 + c - 'A') % mod;
            partSize++;
        }
    }

    cout << res;
}