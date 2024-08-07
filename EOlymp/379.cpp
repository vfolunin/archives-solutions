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

    s.back() = (count(s.begin(), s.end(), '1') + (s.back() == 'o')) % 2 + '0';

    cout << s;
}