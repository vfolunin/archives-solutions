#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readScore() {
    string line;
    if (!getline(cin, line))
        return -1;

    int score = 0;
    stringstream ss(line);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            int value = stoi(token);
            if (value < 40)
                return 0;
            score += value;
        }
    }
    return score;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int seatCount;
    cin >> seatCount;
    cin.get();

    vector<int> scores;
    while (1) {
        int score = readScore();
        if (score == -1)
            break;
        if (score)
            scores.push_back(score);
    }

    if (scores.size() <= seatCount) {
        cout << 0;
        return 0;
    }

    sort(scores.rbegin(), scores.rend());

    if (scores[0] == scores[seatCount]) {
        cout << 1;
        return 0;
    }

    int i = seatCount - 1;
    while (scores[i] == scores[seatCount])
        i--;

    cout << scores[i];
}