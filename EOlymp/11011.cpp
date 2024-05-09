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

    string s(4, ' ');
    for (char &c : s)
        cin >> c;

    sort(s.begin(), s.end());
    int minValue = stoi(s);

    reverse(s.begin(), s.end());
    int maxValue = stoi(s);

    cout << maxValue - minValue;
}