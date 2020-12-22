#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    while (getline(cin, s))
        cout << s << "\n";
}