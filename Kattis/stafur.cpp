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

    char c;
    cin >> c;

    string vowels = "AEIOU";

    if (c == 'Y')
        cout << "Kannski";
    else if (vowels.find(c) != -1)
        cout << "Jebb";
    else
        cout << "Neibb";
}