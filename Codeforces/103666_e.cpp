#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Participant {
    int grade, score, index;

    bool operator < (const Participant &that) {
        return score > that.score;
    }

    friend istream &operator >> (istream &in, Participant &p) {
        in >> p.grade;
        p.score = 0;
        for (int i = 0; i < 5; i++) {
            int value;
            in >> value;
            p.score += value;
        }
        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<Participant> participants(size);
    for (int i = 0; i < participants.size(); i++) {
        cin >> participants[i];
        participants[i].index = i;
    }
    sort(participants.begin(), participants.end());

    vector<int> a;
    for (int i = 0; i < 4; i++)
        a.push_back(participants[i].index);
    sort(a.begin(), a.end());

    vector<int> b;
    for (int i = 4; b.size() < 4; i++)
        if (participants[i].grade != 11)
            b.push_back(participants[i].index);
    sort(b.begin(), b.end());

    for (vector<int> team : { a, b }) {
        for (int index : team)
            cout << index + 1 << " ";
        cout << "\n";
    }
}