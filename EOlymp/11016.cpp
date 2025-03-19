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

    int dot = s.find('.');

    int sumA = 0;
    for (int i = 0; i < dot; i++)
        sumA += s[i] - '0';

    int sumB = 0;
    for (int i = dot + 1; i < s.size(); i++)
        sumB += s[i] - '0';

    cout << sumA << " " << sumB;
}