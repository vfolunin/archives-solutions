#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int studentCount;
    cin >> studentCount;

    if (!studentCount)
        return 0;

    vector<int> bestIds;
    int bestScore = -1;

    for (int i = 0; i < studentCount; i++) {
        int id, score;
        cin >> id >> score;

        if (bestScore < score) {
            bestScore = score;
            bestIds.clear();
        }

        if (bestScore == score)
            bestIds.push_back(id);
    }

    cout << "Turma " << test << "\n";
    for (int id : bestIds)
        cout << id << " ";
    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}