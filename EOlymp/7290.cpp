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

    string letters = "abdegopq";
    int res = 0;

    for (char c : s)
        res += letters.find(c) != -1;

    cout << res;
}