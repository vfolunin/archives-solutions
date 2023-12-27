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

    int i = s.size() - 1;
    while (i >= 0 && s[i] == '9') {
        s[i] = '0';
        i--;
    }

    if (i >= 0)
        s[i]++;
    else
        cout << "1";
    cout << s;
}