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

    int size, limit;
    cin >> size >> limit;

    vector<int> score(2);
    for (int i = 0; i < size; i++) {
        int team, dist;
        cin >> team >> dist;
        team--;

        if (dist == -1)
            score[team]++;
        else if (dist <= limit)
            score[team] += 2;
        else
            score[team] += 3;
    }

    cout << score[0] << ":" << score[1];
}