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

    int avgMark = 0, minMark = 1e9;
    for (char &c : s) {
        int mark = 'Z' - c;
        avgMark += mark;
        minMark = min(minMark, mark);
    }
    avgMark = avgMark / s.size() + (avgMark % s.size() * 2 >= s.size());
    minMark++;

    cout << (char)('Z' - min(avgMark, minMark));
}