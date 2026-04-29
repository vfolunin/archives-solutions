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

    string vowels = "aeiouy";

    string res;
    for (char c : s)
        if (res.empty() || vowels.find(res.back()) == -1 || vowels.find(c) == -1)
            res += c;

    cout << res;
}