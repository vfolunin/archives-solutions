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

    int size;
    string s;
    cin >> size >> s;

    for (int i = 0, value = 1; 1; value++) {
        string part = to_string(value);
        if (s.substr(i, part.size()) != part) {
            cout << value;
            break;
        }
        i += part.size();
    }
}