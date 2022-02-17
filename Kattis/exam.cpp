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

    int correctCount;
    string a, b;
    cin >> correctCount >> a >> b;

    int incorrectCount = a.size() - correctCount, equalCount = 0, unequalCount = 0;
    for (int i = 0; i < a.size(); i++) {
        equalCount += a[i] == b[i];
        unequalCount += a[i] != b[i];
    }

    cout << min(correctCount, equalCount) + min(incorrectCount, unequalCount);
}