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

    vector<int> aceCount(playerCount);
    for (int i = 0; i < cardCount; i++) {
        int value;
        cin >> value;

        aceCount[i % playerCount] += value == 14;
    }

    cout << (playerCount - (max_element(aceCount.begin(), aceCount.end()) - aceCount.begin())) % playerCount + 1;
}