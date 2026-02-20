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
    cin >> size;

    int value = 0, maxValue = 0;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        if (s == "/") {
            value = (maxValue / 10 + 1) * 10;
        } else {
            value = stoi(s);
            maxValue = max(maxValue, value);
        }

        cout << value << "\n";
    }
}