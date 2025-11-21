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
    cin >> s >> s;

    unordered_map<char, int> count;
    for (char c : s)
        count[c]++;

    cout << min(count['U'], count['D']) + min(count['L'], count['R']);
}