#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<char, string> code;
    for (int i = 0; i < size; i++) {
        char c;
        cin >> c >> code[c];
    }

    string s;
    cin >> s;

    for (char c : s)
        cout << code[c];
}