#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    unordered_map<string, string> descr = {
        { "JB", "junior boys" },
        { "JG", "junior girls" },
        { "MB", "midget boys" },
        { "MG", "midget girls" },
        { "SB", "senior boys" },
        { "SG", "senior girls" }
    };

    if (descr.count(s))
        cout << descr[s];
    else
        cout << "invalid code";
}