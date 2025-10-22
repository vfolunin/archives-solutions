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

    string text, pattern;
    cin >> text >> pattern;

    for (int i = 0; i < pattern.size(); i++) {
        if (text.find(pattern) != -1) {
            cout << "yes";
            return 0;
        }

        rotate(pattern.begin(), pattern.begin() + 1, pattern.end());
    }

    cout << "no";
}