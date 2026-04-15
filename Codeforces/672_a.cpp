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

    string s;
    for (int value = 1; s.size() < index; value++)
        s += to_string(value);

    cout << s[index - 1];
}