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
    cin >> s >> s;

    string res = s;
    for (int from = 1; from < s.size(); from++)
        res = min(res, s.substr(from));

    cout << res;
}