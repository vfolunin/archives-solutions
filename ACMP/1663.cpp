#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Cat {
    string name;
    int value, score = 0;

    bool operator < (const Cat &that) const {
        if (score != that.score)
            return score > that.score;
        return name < that.name;
    }

    friend istream &operator >> (istream &in, Cat &cat) {
        return in >> cat.name >> cat.value;
    }

    friend ostream &operator << (ostream &out, Cat &cat) {
        return out << cat.name << " " << cat.score;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int catCount;
    cin >> catCount;

    vector<Cat> cats(catCount);
    for (Cat &cat : cats)
        cin >> cat;

    int pointCount;
    cin >> pointCount;

    for (int i = 0; i < pointCount; i++) {
        int l, r, points;
        cin >> l >> r >> points;

        for (Cat &cat : cats)
            if (l <= cat.value && cat.value <= r)
                cat.score += points;
    }

    sort(cats.begin(), cats.end());

    for (Cat &cat : cats)
        cout << cat << "\n";
}