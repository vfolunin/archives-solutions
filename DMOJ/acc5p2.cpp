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

    if (s.find("DMOJ") != -1)
        cout << 0;
    else if (s.find("DMO") != -1 || s.find("DMJ") != -1 || s.find("DOJ") != -1 || s.find("MOJ") != -1)
        cout << 1;
    else if (s.find("DM") != -1 || s.find("DO") != -1 || s.find("DJ") != -1 || s.find("MO") != -1 || s.find("MJ") != -1 || s.find("OJ") != -1)
        cout << 2;
    else if (s.find("D") != -1 || s.find("M") != -1 || s.find("O") != -1 || s.find("J") != -1)
        cout << 3;
    else
        cout << 4;
    cout << "\n";
}