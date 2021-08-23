#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size, letterCount;
    if (!(cin >> size >> letterCount))
        return 0;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    map<char, int> count;

    for (int y1 = 0; y1 < size; y1++) {
        for (int x1 = 0; x1 < size; x1++) {
            for (int y2 = 0; y2 < size; y2++) {
                for (int x2 = 0; x2 < size; x2++) {
                    if (y1 == y2 && x1 == x2 || a[y1][x1] != a[y2][x2])
                        continue;

                    int y12 = y2 - y1, x12 = x2 - x1;
                    int y13 = -x12, x13 = y12;
                    int y3 = y1 + y13, x3 = x1 + x13;
                    int y4 = y3 + y12, x4 = x3 + x12;

                    if (0 <= y3 && y3 < size && 0 <= x3 && x3 < size &&
                        0 <= y4 && y4 < size && 0 <= x4 && x4 < size &&
                        a[y1][x1] == a[y3][x3] && a[y1][x1] == a[y4][x4])
                        count[a[y1][x1]]++;
                }
            }
        }
    }

    if (test)
        cout << "\n";
    for (int i = 0; i < letterCount; i++) {
        char letter;
        cin >> letter;
        cout << letter << " " << count[letter] / 4 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}