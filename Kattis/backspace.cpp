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
    cin >> text;

    string resText;
    for (char c : text) {
        if (c == '<')
            resText.pop_back();
        else
            resText += c;
    }

    cout << resText;
}