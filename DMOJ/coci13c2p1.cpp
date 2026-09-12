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

    int player, questionCount;
    cin >> player >> questionCount;
    player--;

    int totalTime = 0;
    for (int i = 0; i < questionCount; i++) {
        int time;
        char answer;
        cin >> time >> answer;

        totalTime += time;
        if (totalTime >= 210) {
            cout << player + 1;
            return 0;
        }

        if (answer == 'T')
            player = (player + 1) % 8;
    }
}