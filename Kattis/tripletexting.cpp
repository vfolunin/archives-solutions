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

    int size = text.size() / 3;
    for (int i = 0; i < size; i++) {
        if (text[i] == text[i + size])
            cout << text[i];
        else
            cout << text[i + 2 * size];
    }
}