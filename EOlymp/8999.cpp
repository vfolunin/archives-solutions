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

    char c = *max_element(s.begin(), s.end());

    cout << c << " " << count(s.begin(), s.end(), c);
}