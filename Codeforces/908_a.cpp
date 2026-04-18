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
    cin >> s;

    string vowels = "aeiou";
    string odd = "13579";

    int res = 0;
    for (char c : s)
        res += vowels.find(c) != -1 || odd.find(c) != -1;

    cout << res;
}