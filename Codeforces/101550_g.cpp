#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int maxStars(int rank) {
    if (rank >= 21)
        return 2;
    if (rank >= 16)
        return 3;
    if (rank >= 11)
        return 4;
    return 5;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string results;
    cin >> results;

    int rank = 25, stars = 0, winStreak = 0;

    for (char result : results) {
        if (result == 'W') {
            winStreak++;

            stars += 1 + (rank >= 6 && winStreak >= 3);
            if (stars > maxStars(rank)) {
                stars -= maxStars(rank);
                rank--;

                if (!rank) {
                    cout << "Legend";
                    return 0;
                }
            }
        } else {
            winStreak = 0;

            if (rank > 20)
                continue;

            stars--;
            if (stars < 0) {
                if (rank == 20) {
                    stars = 0;
                } else {
                    rank++;
                    stars += maxStars(rank);
                }
            }
        }
    }

    cout << rank;
}