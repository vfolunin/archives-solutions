#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Participant {
    double score;
    string name;

    bool operator < (const Participant &that) const {
        return score > that.score;
    }

    friend istream &operator >> (istream &in, Participant &p) {
        return in >> p.score >> p.name;
    }

    friend ostream &operator << (ostream &out, Participant &p) {
        out.precision(2);
        return out << fixed << p.score << " " << p.name;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int roomCount;
    cin >> roomCount;

    vector<Participant> participants;

    for (int i = 0; i < roomCount; i++) {
        int participantCount;
        cin >> participantCount;

        for (int j = 0; j < participantCount; j++) {
            Participant participant;
            cin >> participant;

            participants.push_back(participant);
        }
    }

    sort(participants.begin(), participants.end());

    cout << participants.size() << "\n";
    for (Participant &participant : participants)
        cout << participant << "\n";
}