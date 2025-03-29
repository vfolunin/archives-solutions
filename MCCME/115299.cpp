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

    reverse(s.begin(), s.end());

    for (char &c : s)
        if (c == '2' || c == '5')
            c = '2' + '5' - c;

    cout << stoll(s);
}