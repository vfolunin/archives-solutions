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

    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] < s[i + 1]) {
            swap(s[i], s[i + 1]);
            break;
        }
    }

    cout << s;
}