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

    string s;
    getline(cin, s);

    string buttons = "22233344455566677778889999";
    for (char c : s) {
        if (c == ' ') {
            cout << "0 ";
        } else {
            int index = c - 'A';
            char button = buttons[index];
            cout << string(index - buttons.find(button) + 1, button) << " ";
        }
    }
}