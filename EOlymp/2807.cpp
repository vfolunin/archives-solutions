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

    char res = 0;
    for (char c : s)
        res ^= c;

    if (res)
        cout << res;
    else
        cout << "Ok";
}