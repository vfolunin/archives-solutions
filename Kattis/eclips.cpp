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

    bool found = 0;
    for (string s; cin >> s; ) {
        if (s.find('e') != -1) {
            found = 1;
            cout << s << " ";
        }
    }

    if (!found)
        cout << "oh noes";
}