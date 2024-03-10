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

    int opCount;
    cin >> opCount;

    int y = 0, x = 0;
    for (int i = 0; i < opCount; i++) {
        char type;
        int stepCount;
        cin >> type >> stepCount;

        if (type == 'X') {
            y += stepCount * 2;
        } else if (type == 'Y') {
            y += stepCount;
            x += stepCount * 2;
        } else {
            y -= stepCount;
            x += stepCount * 2;
        }
    }

    vector<string> res;
    while (y || x) {
        if (x < 0 && y <= 0) {
            res.push_back("Y 1");
            x += 2;
            y++;
        } else if (x < 0 && y > 0) {
            res.push_back("Z 1");
            x += 2;
            y--;
        } else if (x == 0 && y < 0) {
            res.push_back("X 1");
            y += 2;
        } else if (x == 0 && y > 0) {
            res.push_back("X -1");
            y -= 2;
        } else if (x > 0 && y <= 0) {
            res.push_back("Z -1");
            x -= 2;
            y++;
        } else {
            res.push_back("Y -1");
            x -= 2;
            y--;
        }
    }

    cout << res.size() << "\n";
    for (string &s : res)
        cout << s << "\n";
}