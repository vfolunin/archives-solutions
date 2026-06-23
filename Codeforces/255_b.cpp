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

    int xCount = count(s.begin(), s.end(), 'x');
    int yCount = s.size() - xCount;
    int minCount = min(xCount, yCount);

    cout << string(xCount - minCount, 'x') << string(yCount - minCount, 'y');
}