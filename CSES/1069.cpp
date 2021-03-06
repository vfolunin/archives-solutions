#include <iostream>
#include <iomanip>
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

    int curRep = 1, maxRep = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            curRep++;
        else
            curRep = 1;
        maxRep = max(maxRep, curRep);
    }
    
    cout << maxRep;
}