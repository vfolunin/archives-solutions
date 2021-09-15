#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Player {
    int number;
    string name;
    char role;
    int years;

    bool operator < (const Player &that) const {
        return number < that.number;
        
    }
};

bool compareCaptain(const Player &a, const Player &b) {
    if (a.years != b.years)
        return a.years > b.years;
    return a.number > b.number;
}

istream &operator >> (istream &in, Player &p) {
    in >> p.number;
    if (!p.number)
        return in;

    in >> p.name >> p.role;

    p.years = 0;
    while (in.peek() == ' ') {
        int l, r;
        char hyphen;
        in >> l >> hyphen >> r;
        p.years += r - l + 1;
    }

    return in;
}

ostream &operator << (ostream &out, const Player &p) {
    out << p.number << " " << p.name << " " << p.role;
    return out;
}

bool solve() {
    vector<Player> players(22);

    for (Player &player : players) {
        cin >> player;
        if (!player.number)
            return 0;
    }

    int g = 1, d, m, s;
    char hyphen;
    cin >> d >> hyphen >> m >> hyphen >> s;

    set<Player> sg, sd, sm, ss;
    for (Player &player : players) {
        if (player.role == 'G') {
            sg.insert(player);
            if (sg.size() > g)
                sg.erase(--sg.end());
        }
        if (player.role == 'D') {
            sd.insert(player);
            if (sd.size() > d)
                sd.erase(--sd.end());
        }
        if (player.role == 'M') {
            sm.insert(player);
            if (sm.size() > m)
                sm.erase(--sm.end());
        }
        if (player.role == 'S') {
            ss.insert(player);
            if (ss.size() > s)
                ss.erase(--ss.end());
        }
    }

    if (sg.size() < g || sd.size() < d || sm.size() < m || ss.size() < s) {
        cout << "IMPOSSIBLE TO ARRANGE\n\n";
        return 1;
    }

    vector<set<Player>> playerSets = { sg, sd, sm, ss };

    const Player *captain = &*sg.begin();
    for (set<Player> &playerSet : playerSets)
        for (const Player &player : playerSet)
            if (compareCaptain(player, *captain))
                captain = &player;

    cout << *captain << "\n";
    for (set<Player> &s : playerSets)
        for (const Player &player : s)
            if (player.number != captain->number)
                cout << player << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}