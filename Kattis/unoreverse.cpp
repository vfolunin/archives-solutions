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

    int playerCount, cardCount;
    cin >> playerCount >> cardCount;

    if (cardCount == 0)
        cout << "NO";
    else if (cardCount == 1)
        cout << "YES";
    else if (playerCount == 2)
        cout << "YES";
    else if (cardCount % 2)
        cout << "MAYBE";
    else if (cardCount >= 2 * (playerCount - 1))
        cout << "MAYBE";
    else
        cout << "NO";
}