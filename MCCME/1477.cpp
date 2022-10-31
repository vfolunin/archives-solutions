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

    s = string(4 - s.size(), '0') + s;

    cout << equal(s.begin(), s.end(), s.rbegin());
}