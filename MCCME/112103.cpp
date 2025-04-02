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

    int size;
    string s;
    cin >> size >> s;

    int l = (size - s.size()) / 2;
    int r = size - s.size() - l;

    cout << string(l, '.') << s << string(r, '.');
}