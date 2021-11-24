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

    string num;
    cin >> num;

    int res = 0;
    for (char d : num)
        res = (res + d - '0') % 3;

    cout << res << "\n";
}