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

    long long limit;
    string s;
    cin >> limit >> limit >> s;

    long long aCount = 0, bCount = 0, abCount = 0;
    int res = 0;

    for (int l = 0, r = 0; r < s.size(); r++) {
        if (s[r] == 'a') {
            aCount++;
        } else if (s[r] == 'b') {
            abCount += aCount;
            bCount++;
        }

        while (abCount > limit) {
            if (s[l] == 'a') {
                abCount -= bCount;
                aCount--;
            } else if (s[l] == 'b') {
                bCount--;
            }
            l++;
        }

        res = max(res, r - l + 1);
    }

    cout << res;
}