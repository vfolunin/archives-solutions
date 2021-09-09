#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Box {
    int size, free;
    vector<Box *> inner;

    bool canReceive(Box &that) {
        for (Box *box : inner)
            if (box->canReceive(that))
                return 1;
        return free >= that.size;
    }

    void receive(Box &that) {
        for (Box *box : inner) {
            if (box->canReceive(that)) {
                box->receive(that);
                return;
            }
        }
        free -= that.size;
        inner.push_back(&that);
    }
};

bool solve() {
    int boxCount;
    if (!(cin >> boxCount))
        return 0;

    vector<Box> boxes(boxCount);
    for (Box &box : boxes) {
        cin >> box.size;
        box.free = box.size;
    }

    Box pile;
    pile.size = pile.free = 1e9;
    for (Box &box : boxes)
        pile.receive(box);

    cout << pile.size - pile.free << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}