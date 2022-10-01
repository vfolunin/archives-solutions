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

    int pos = s.find('f');
    if (pos == -1) {
        cout << -2;
        return 0;
    }

    pos = s.find('f', pos + 1);
    cout << pos;
}