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
    int mod;
    cin >> s >> mod;

    int res = 0;
    for (char c : s)
        res = (res * 10 + c - '0') % mod;

    cout << res;
}