#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int playerCount;
    cin >> playerCount;

    unordered_map<string, int> score;
    for (int i = 0; i < playerCount; i++) {
        string player;
        cin >> player;

        score[player];
    }

    int throwCount;
    cin >> throwCount;

    int prevA = 0, prevB = 0;
    string bestPlayer = score.begin()->first;
    for (int i = 0; i < throwCount; i++) {
        int a, b;
        char colon;
        string player;
        cin >> a >> colon >> b >> player;

        score[player] += a - prevA + b - prevB;
        if (score[bestPlayer] < score[player])
            bestPlayer = player;

        prevA = a;
        prevB = b;
    }

    cout << bestPlayer << " " << score[bestPlayer];
}