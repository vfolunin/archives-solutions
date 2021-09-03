#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toLower(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return toLower(a.first) < toLower(b.first);
}

bool solve(int test) {
    int participantCount;
    if (!(cin >> participantCount))
        return 0;

    vector<pair<string, int>> participants(participantCount);
    for (auto &[name, score] : participants) {
        cin.ignore();
        while (cin.peek() != ';')
            name += cin.get();

        score = 0;
        for (int i = 0; i < 5; i++) {
            cin.ignore();
            for (int j = 0; j < 5; j++) {
                int x;
                cin >> x;
                if (x)
                    score += (j < 4 ? 1 : 2);
            }
        }
    }

    sort(participants.begin(), participants.end(), compare);

    cout << "Case " << test << ":\n";
    for (auto &[name, score] : participants)
        cout << name << " " << score << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}