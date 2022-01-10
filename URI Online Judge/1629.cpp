#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int res = 0;
    while (n > 9) {
        res += n % 10;
        n /= 10;
    }
    res += n;
    return res;
}

bool solve() {
    int codeCount;
    cin >> codeCount;

    if (!codeCount)
        return 0;

    for (int i = 0; i < codeCount; i++) {
        string code;
        cin >> code;

        vector<int> count(2);
        for (int i = 0; i < code.size(); i++)
            count[i % 2] += code[i] - '0';

        cout << digitSum(count[0]) + digitSum(count[1]) << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}