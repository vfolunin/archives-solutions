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
    getline(cin, s);

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += s.substr(i, 9) == "certainly";

    cout << res;
}