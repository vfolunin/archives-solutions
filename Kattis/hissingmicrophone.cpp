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

    if (text.find("ss") == -1)
        cout << "no ";
    cout << "hiss";
}