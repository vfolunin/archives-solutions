#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int replace(string s, char a, char b) {
    replace(s.begin(), s.end(), a, b);
    return stoi(s);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    cout << replace(a, '6', '5') + replace(b, '6', '5') << " ";
    cout << replace(a, '5', '6') + replace(b, '5', '6');
}