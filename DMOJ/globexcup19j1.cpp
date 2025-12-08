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

    int opponentCount, rating, deltaWin, deltaLose, gameCount;
    cin >> opponentCount >> rating >> deltaWin >> deltaLose >> gameCount;

    vector<int> gameResult(opponentCount);
    for (int &result : gameResult)
        cin >> result;

    for (int i = 0; i < gameCount; i++) {
        int opponent;
        cin >> opponent;

        rating += gameResult[opponent - 1] ? deltaWin : -deltaLose;
    }

    cout << rating;
}