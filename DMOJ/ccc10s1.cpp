#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Computer {
    string name;
    int score;

    bool operator < (const Computer &that) const {
        if (score != that.score)
            return score > that.score;
        return name < that.name;
    }

    friend istream &operator >> (istream &in, Computer &computer) {
        int a, b, c;
        in >> computer.name >> a >> b >> c;
        computer.score = 2 * a + 3 * b + c;
        return in;
    }

    friend ostream &operator << (ostream &out, Computer &computer) {
        return out << computer.name;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int computerCount;
    cin >> computerCount;

    vector<Computer> computers(computerCount);
    for (Computer &computer : computers)
        cin >> computer;

    sort(computers.begin(), computers.end());

    for (int i = 0; i < computers.size() && i < 2; i++)
        cout << computers[i] << "\n";
}