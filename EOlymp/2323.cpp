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

    sort(s.rbegin(), s.rend());
    int maxValue = stoi(s);

    reverse(s.begin(), s.end());
    int minValue = stoi(s);

    cout << maxValue + minValue;
}