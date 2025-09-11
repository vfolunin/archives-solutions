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

    int size, shift;
    cin >> size >> shift;

    string s(size, ' ');
    for (char &c : s)
        cin >> c;

    rotate(s.begin(), s.begin() + shift % s.size(), s.end());

    cout << s.substr(0, 10);
}