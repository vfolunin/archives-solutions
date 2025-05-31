#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hero {
    string name;
    vector<int> stats;

    bool operator < (const Hero &that) const {
        if (stats[0] != that.stats[0])
            return stats[0] > that.stats[0];
        if (stats[1] != that.stats[1])
            return stats[1] > that.stats[1];
        if (stats[2] != that.stats[2])
            return stats[2] < that.stats[2];
        return name < that.name;
    }

    friend istream &operator >> (istream &in, Hero &hero) {
        in >> hero.name;
        hero.stats.resize(3);
        for (int &stat : hero.stats)
            in >> stat;
        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int heroCount;
    cin >> heroCount;

    vector<Hero> heroes(heroCount);
    for (Hero &hero : heroes)
        cin >> hero;

    sort(heroes.begin(), heroes.end());

    for (auto &[name, _] : heroes)
        cout << name << "\n";
}