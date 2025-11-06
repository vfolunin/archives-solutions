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

    int size;
    cin >> size;

    int totalScore = 0;
    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;

        int r2 = x * x + y * y;
        for (int r = 10, score = 10; score; r += 20, score--) {
            if (r2 <= r * r) {
                totalScore += score;
                break;
            }
        }
    }

    cout << totalScore;
}