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

    sort(s.begin(), s.end());
    int i = 0;
    while (s[i] == '0')
        i++;
    swap(s[0], s[i]);
    cout << s << " ";

    sort(s.rbegin(), s.rend());
    cout << s;
}