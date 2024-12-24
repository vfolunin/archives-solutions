#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool beats(char type, int dx, int dy) {
    return type == 'K' && dx <= 1 && dy <= 1 ||
        type == 'Q' && (dx == dy || dx * dy == 0) ||
        type == 'R' && dx * dy == 0 ||
        type == 'N' && dx * dy == 2 ||
        type == 'B' && dx == dy;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    char type1, x1, y1;
    cin >> type1 >> x1 >> y1;
    x1 -= 'a';
    y1 -= '1';

    char type2, x2, y2;
    cin >> type2 >> x2 >> y2;
    x2 -= 'a';
    y2 -= '1';

    int dx = abs(x1 - x2), dy = abs(y1 - y2);
    bool beats1 = beats(type1, dx, dy), beats2 = beats(type2, dx, dy);

    if (!beats1 && !beats2)
        cout << "NONE";
    else if (!beats1 && beats2)
        cout << "BLACK";
    else if (beats1 && !beats2)
        cout << "WHITE";
    else
        cout << "BOTH";
}