#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, int i, int maxValue, string &s) {
    if (i == size) {
        cout << s << "\n";
        return;
    }

    for (int value = 0; value < maxValue; value++) {
        s.push_back(value + '0');
        rec(size, i + 1, maxValue, s);
        s.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, maxValue;
    cin >> size >> maxValue;

    string s;
    rec(size, 0, maxValue, s);
}