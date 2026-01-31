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
        if ('0' <= token[0] && token[0] <= '9') {
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

    map<int, int> scoreCount;
    while (1) {
        int score = readScore();
        if (score == -1)
            break;
        if (score)
            scoreCount[score]++;
    }

    for (auto it2 = prev(scoreCount.end()), it1 = prev(it2); it2 != scoreCount.begin(); it1--, it2--)
        it1->second += it2->second;

    for (auto it1 = scoreCount.begin(), it2 = next(it1); it1 != scoreCount.end(); it1++, it2++) {
        if (it1->second > seatCount && (it2 != scoreCount.end() ? it2->second : 0) < seatCount) {
            cout << it1->first;
            return 0;
        }
    }

    cout << 0;
}