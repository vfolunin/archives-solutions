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

    int money, moveCount;
    cin >> money >> moveCount;

    map<char, int> m = { {'D', money}, {'E', money}, {'F', money} };

    for (int i = 0; i < moveCount; i++) {
        char type, player;
        cin >> type >> player;

        if (type == 'C') {
            int price;
            cin >> price;
            m[player] -= price;
        } else if (type == 'V') {
            int price;
            cin >> price;
            m[player] += price;
        } else {
            char player2;
            int price;
            cin >> player2 >> price;
            m[player] += price;
            m[player2] -= price;
        }
    }

    cout << m['D'] << " " << m['E'] << " " << m['F'] << "\n";
}