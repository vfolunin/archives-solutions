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

    int moveCount;
    char initCup;
    cin >> moveCount >> initCup;

    string cups = "000";
    cups[initCup - 'A'] = '1';

    for (int i = 0; i < moveCount; i++) {
        int move;
        cin >> move;
        swap(cups[move - 1], cups[move % 3]);
    }

    cout << (char)('A' + cups.find('1')) << "\n";
}