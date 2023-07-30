#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(string s, int i) {
    s.erase(s.begin() + i);
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += (s[i] - '0') * (i % 2 ? -1 : 1);
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int res = getSum(s, 0);
    for (int i = 1; i < s.size(); i++)
        res = max(res, getSum(s, i));

    cout << res;
}