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

    int offset = 0;
    for (string s; cin >> s; ) {
        cout << string(offset, '.') << s << "\n";
        offset += s.size();
    }
}