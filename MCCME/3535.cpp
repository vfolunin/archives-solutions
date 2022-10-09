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

    vector<string> img = {
        "   _~_    ",
        "  (o o)   ",
        " /  V  \\  ",
        "/(  _  )\\ ",
        "  ^^ ^^   "
    };

    int n;
    cin >> n;

    for (string &row : img) {
        for (int i = 0; i < n; i++)
            cout << row;
        cout << "\n";
    }
}