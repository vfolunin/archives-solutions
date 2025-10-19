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

    string s = "9780921418000";
    for (int i = s.size() - 3; i < s.size(); i++)
        cin >> s[i];

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += (s[i] - '0') * (i % 2 ? 3 : 1);

    cout << "The 1-3-sum is " << res;
}