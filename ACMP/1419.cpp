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

    vector<string> a(5);
    for (string &s : a) {
        cin >> s;

        while (s.back() == '0')
            s.pop_back();
        reverse(s.begin(), s.end());
    }

    reverse(a.begin(), a.end());

    for (string &s : a)
        cout << s << " ";
}