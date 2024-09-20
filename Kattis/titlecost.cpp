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
    double value;
    cin >> s >> value;

    cout.precision(8);
    cout << fixed << min<double>(s.size(), value);
}