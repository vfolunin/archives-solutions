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

    if (s.front() > s.back())
        cout << s.front();
    else if (s.front() < s.back())
        cout << s.back();
    else
        cout << "=";
}