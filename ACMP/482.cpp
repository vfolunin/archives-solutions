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

    int index;
    cin >> index;
    index--;

    for (int blockLen = 1; 1; blockLen++) {
        for (int i = 1; i <= blockLen; i++) {
            string s = to_string(i);
            if (index >= s.size()) {
                index -= (int)s.size();
            } else {
                cout << s[index];
                return 0;
            }
        }
    }
}