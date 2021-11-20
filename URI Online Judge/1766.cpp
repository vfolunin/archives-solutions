#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Deer {
    string name;
    int weight, age;
    double height;

    bool operator < (const Deer &that) const {
        if (weight != that.weight)
            return weight > that.weight;
        if (age != that.age)
            return age < that.age;
        if (height != that.height)
            return height < that.height;
        return name < that.name;
    }
};

void solve(int test) {
    int deerCount, slotCount;
    cin >> deerCount >> slotCount;

    vector<Deer> deers(deerCount);
    for (auto &[n, w, a, h] : deers)
        cin >> n >> w >> a >> h;
    sort(deers.begin(), deers.end());

    cout << "CENARIO {" << test << "}\n";
    for (int i = 0; i < slotCount; i++)
        cout << i + 1 << " - " << deers[i].name << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}