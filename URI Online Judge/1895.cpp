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

    int cardCount, tableCard, threshold;
    cin >> cardCount >> tableCard >> threshold;

    vector<int> score(2);

    for (int i = 0; i < cardCount; i++) {
        int card;
        cin >> card;
        int diff = abs(tableCard - card);
        if (diff <= threshold) {
            tableCard = card;
            score[i % 2] += diff;
        }
    }

    cout << score[0] << " " << score[1] << "\n";
}