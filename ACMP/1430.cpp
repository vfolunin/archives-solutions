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

    string a, b;
    cin >> a >> b;

    vector<int> aCount(10);
    for (char c : a)
        aCount[c - '0']++;

    vector<int> bCount(10);
    for (char c : b)
        bCount[c - '0']++;

    string res;
    for (int i = aCount.size() - 1; i; i--)
        res += string(min(aCount[i], bCount[i]), i + '0');

    if (aCount[0] && bCount[0]) {
        if (res.empty())
            res = "0";
        else
            res += string(min(aCount[0], bCount[0]), '0');
    }

    if (res.empty())
        res = "No solution";

    cout << res;
}