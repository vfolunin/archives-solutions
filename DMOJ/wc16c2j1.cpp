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

    int size;
    cin >> size;

    string res = "None";
    int resWin = -1;

    for (int i = 0; i < size; i++) {
        string name;
        int win, lose;
        cin >> name >> win >> lose;

        if (resWin < win && !lose) {
            res = name;
            resWin = win;
        }
    }

    cout << res;
}