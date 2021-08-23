#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Groom {
    int a, b;

    bool operator < (const Groom &that) const {
        if (a != that.a)
            return a < that.a;
        return b < that.b;
    }

    bool dominates(const Groom &that) const {
        return a < that.a && b <= that.b || a <= that.a && b < that.b;
    }
};

void solve(int test) {
    int groomCount;
    cin >> groomCount;

    multiset<Groom> efficientGrooms;

    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << ":\n";

    for (int i = 0; i < groomCount; i++) {
        Groom g;
        cin >> g.a >> g.b;

        bool efficient = 1;
        if (efficientGrooms.find(g) == efficientGrooms.end()) {
            for (auto it = efficientGrooms.begin(); it != efficientGrooms.end(); ) {
                if (it->dominates(g)) {
                    efficient = 0;
                    break;
                }
                if (g.dominates(*it))
                    it = efficientGrooms.erase(it);
                else
                    it++;
            }
        }

        if (efficient)
            efficientGrooms.insert(g);

        cout << efficientGrooms.size() << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}