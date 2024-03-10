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

    int res = abs(x) / 2;
    if (abs(y) > res)
        res += (abs(y) - res) / 2;
    
    cout << res;
}