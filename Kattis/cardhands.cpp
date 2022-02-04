#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Trie {
    struct Vertex {
        map<string, Vertex> next;
    } root;

    void add(const vector<string> &hand) {
        Vertex *v = &root;
        for (const string &card : hand)
            v = &v->next[card];
    }

    int size(Vertex *v) {
        if (!v)
            return 0;

        int res = 1;
        for (auto &[_, to] : v->next)
            res += size(&to);
        return res;
    }

    int size() {
        return size(&root);
    }
};

bool solve() {
    int handCount;
    cin >> handCount;

    if (!handCount)
        return 0;

    Trie hands;

    for (int i = 0; i < handCount; i++) {
        int handSize;
        cin >> handSize;

        vector<string> hand(handSize);
        for (string &card : hand)
            cin >> card;

        reverse(hand.begin(), hand.end());
        hands.add(hand);
    }

    cout << hands.size() - 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}