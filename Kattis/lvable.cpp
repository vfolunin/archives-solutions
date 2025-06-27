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
    cin >> s >> s;

    if (s.find("lv") != -1)
        cout << 0;
    else if (s.find("l") != -1 || s.find("v") != -1)
        cout << 1;
    else
        cout << 2;
}