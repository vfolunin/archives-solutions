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
    getline(cin, s);

    reverse(s.begin(), s.end());
    while (!s.empty() && s.back() == ' ')
        s.pop_back();
    reverse(s.begin(), s.end());

    cout << s;
}