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

    string text;
    getline(cin, text);

    string vowels = "aeiou";
    for (int i = 0; i < text.size(); i++) {
        cout << text[i];
        if (vowels.find(text[i]) != -1)
            i += 2;
    }
}