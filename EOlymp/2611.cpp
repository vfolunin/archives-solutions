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
    char a, b;
    cin >> s >> a >> b;

    for (char &c : s)
        if (c == a)
            c = b;

    cout << stoll(s);
}