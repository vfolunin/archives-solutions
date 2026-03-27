#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int naiveSimulate(int bet, vector<int> &score, unordered_map<int, vector<int>> &betters) {
    vector<int> curScore = score;
    unordered_map<int, vector<int>> curBetters = betters;

    curBetters[bet].push_back(score.size() - 1);

    for (int i = 1; i <= 101; i++) {
        if (curBetters[i].size() == 1) {
            curScore[curBetters[i][0]] += i;
            break;
        }
    }

    int res = 0;
    for (int i = 0; i < curScore.size() - 1; i++)
        res += curScore[i] < curScore.back();
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> score(size), bets(size);
    unordered_map<int, vector<int>> betters;

    for (int &value : score)
        cin >> value;

    for (int i = 0; i < bets.size(); i++) {
        cin >> bets[i];
        betters[bets[i]].push_back(i);
    }

    int bestRes = -1;
    int bestBet = -1;

    for (int bet = 1; bet <= 101; bet++) {
        int res = naiveSimulate(bet, score, betters);
        if (res > bestRes) {
            bestRes = res;
            bestBet = bet;
        }
    }

    cout << bestBet << endl;
}