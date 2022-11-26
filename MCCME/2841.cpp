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

    string s(3, ' ');
    cin >> s[0] >> s[1] >> s[2];

    sort(s.rbegin(), s.rend());
    while (s.back() % 2)
        prev_permutation(s.begin(), s.end());

    cout << s;
}