#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> getScoreAndMoment(int size) {
    int score = 0, moment = size;
    vector<int> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        score += a[i];
        if (i >= 2 && a[i] == a[i - 1] && a[i] == a[i - 2] && moment == size)
            moment = i;
    }
    return { score, moment };
}

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    auto [aScore, aMoment] = getScoreAndMoment(size);
    auto [bScore, bMoment] = getScoreAndMoment(size);

    if (aMoment < bMoment)
        aScore += 30;
    if (aMoment > bMoment)
        bScore += 30;

    if (aScore > bScore)
        cout << "M\n";
    else if (aScore == bScore)
        cout << "T\n";
    else
        cout << "L\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}