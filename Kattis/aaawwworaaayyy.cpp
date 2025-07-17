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

    int h, w, targetI;
    cin >> h >> w >> targetI;
    targetI--;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    for (int i = h - 1; i >= 0; ) {
        int j = a[i].find('P');
        if (j == -1) {
            i--;
            continue;
        }

        string s;
        cin >> s >> s;

        if (s.back() == '!') {
            a[i][j] = 'A';

            int startI = i - (s.size() - 9);
            rotate(a.begin() + startI, a.begin() + i, a.begin() + i + 1);

            if (targetI == i)
                targetI = startI;
            else if (startI <= targetI && targetI < i)
                targetI++;
        } else {
            a[i][j] = 'R';
        }
    }

    cout << targetI + 1;
}