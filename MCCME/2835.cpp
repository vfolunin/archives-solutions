#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isAlpha(string &s) {
    for (char c : s)
        if (!isalpha(c))
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   
    vector<string> a(3);
    for (string &s : a)
        cin >> s;

    if (isAlpha(a[1]))
        swap(a[0], a[1]);
    else if (isAlpha(a[2]))
        swap(a[0], a[2]);

    if (a[2].find('.') != -1)
        swap(a[1], a[2]);

    for (string &s : a)
        cout << s << "\n";
}