#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Participant {
    string country, name, surname;
    vector<double> scores;

    bool operator < (const Participant &that) const {
        return scores > that.scores;
    }

    friend istream &operator >> (istream &in, Participant &p) {
        in >> p.country >> p.surname >> p.name;
        for (int i = 0; i < 6; i++) {
            string s;
            in >> s;
            if (s != "x")
                p.scores.push_back(stod(s));
        }
        sort(p.scores.rbegin(), p.scores.rend());
        return in;
    }

    friend ostream &operator << (ostream &out, const Participant &p) {
        out.precision(2);
        return out << p.country << " " << p.surname << " " << p.name << " " << fixed << p.scores[0];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int participantCount;
    cin >> participantCount;

    set<Participant> participants;
    for (int i = 0; i < participantCount; i++) {
        Participant participant;
        cin >> participant;

        if (!participant.scores.empty())
            participants.insert(participant);
    }

    int k = 1;
    for (auto it = participants.begin(); it != participants.end() && k <= 3; it++, k++)
        cout << k << ") " << *it << "\n";
    if (k == 1)
        cout << "No results.";
}