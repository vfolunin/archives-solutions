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
    cin >> s;

    if (s.size() >= 2 && s[s.size() - 2] % 2 && s[s.size() - 1] % 2 || s.size() % 2 == 0)
        cout << "Vito";
    else
        cout << "Romario";
}