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

    int size, index;
    cin >> size >> index;
    index--;

    vector<int> score(size);
    for (int &score : score)
        cin >> score;

    vector<int> points(size);
    for (int &points : points)
        cin >> points;

    int totalScore = score[index] + points[0];
    score.erase(score.begin() + index);
    points.erase(points.begin());

    int si = 0, pi = points.size() - 1, res = 1;
    while (si < score.size() && score[si] + points[pi] > totalScore) {
        si++;
        res++;
    }
    for (; si < score.size(); si++, pi--)
        res += score[si] + points[pi] > totalScore;

    cout << res << "\n";
}