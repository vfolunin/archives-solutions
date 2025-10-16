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
    cin >> s >> s;

    int aCount = count(s.begin(), s.end(), 'A');
    if (aCount > s.size() - aCount)
        cout << "A";
    else if (aCount == s.size() - aCount)
        cout << "Tie";
    else
        cout << "B";
}