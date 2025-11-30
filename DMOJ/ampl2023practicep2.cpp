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

    string s = "GOAMPLITUDE", n;
    cin >> n;

    int index = 0;
    for (char c : n)
        index = (index * 10 + c - '0') % s.size();

    cout << s[(index - 1 + s.size()) % s.size()];
}