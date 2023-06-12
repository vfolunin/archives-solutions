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
    int index;
    cin >> s >> index;
    index--;

    int shift = index / s.size() % s.size();
    rotate(s.begin(), s.begin() + shift, s.end());

    cout << s[index % s.size()];
}