#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

struct Team {
    int acCount = 0, penalty = 0;

    bool operator < (const Team &that) const {
        if (acCount != that.acCount)
            return acCount > that.acCount;
        return penalty < that.penalty;
    }

    bool operator == (const Team &that) const {
        return acCount == that.acCount && penalty == that.penalty;
    }
};

class Treap {
    struct Node {
        Team key;
        int priority, nodeSize = 1, subtreeSize = 1;
        Node *left = 0, *right = 0;
        inline static minstd_rand gen;

        Node(const Team &key) : key(key), priority(gen()) {}
    } *root = 0;

    int getSubtreeSize(Node *n) const {
        return n ? n->subtreeSize : 0;
    }

    void update(Node *n) {
        if (n)
            n->subtreeSize = getSubtreeSize(n->left) + n->nodeSize + getSubtreeSize(n->right);
    }

    Node *merge(Node *a, Node *b) {
        if (!a || !b) {
            return a ? a : b;
        }
        if (a->priority > b->priority) {
            a->right = merge(a->right, b);
            update(a);
            return a;
        } else {
            b->left = merge(a, b->left);
            update(b);
            return b;
        }
    }

    void split(Node *t, const Team &key, Node *&a, Node *&b) {
        if (!t) {
            a = b = 0;
            return;
        }
        if (t->key < key) {
            split(t->right, key, t->right, b);
            a = t;
        } else {
            split(t->left, key, a, t->left);
            b = t;
        }
        update(a);
        update(b);
    }

    int indexOf(Node *n, const Team &key) const {
        if (!n) {
            return 0;
        } else if (n->key < key) {
            return getSubtreeSize(n->left) + n->nodeSize + indexOf(n->right, key);
        } else if (n->key == key) {
            return getSubtreeSize(n->left);
        } else {
            return indexOf(n->left, key);
        }
    }
public:
    int indexOf(const Team &key) const {
        return indexOf(root, key);
    }

    void insert(const Team &key) {
        Node *less, *equal, *greater;
        split(root, key, less, equal);
        split(equal, { key.acCount, key.penalty + 1 }, equal, greater);
        if (equal) {
            equal->nodeSize++;
            equal->subtreeSize++;
        } else {
            equal = new Node(key);
        }
        equal = merge(equal, greater);
        root = merge(less, equal);
    }

    void eraseOne(const Team &key) {
        Node *less, *equal, *greater;
        split(root, key, less, equal);
        split(equal, { key.acCount, key.penalty + 1 }, equal, greater);
        if (equal) {
            equal->nodeSize--;
            equal->subtreeSize--;
            if (!equal->nodeSize) {
                equal = 0;
            }
        }
        equal = merge(equal, greater);
        root = merge(less, equal);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamCount, eventCount;
    cin >> teamCount >> eventCount;

    vector<Team> teams(teamCount);

    Treap treap;
    for (int i = 0; i < teamCount; i++)
        treap.insert(teams[i]);

    for (int i = 0; i < eventCount; i++) {
        int teamIndex, deltaPenalty;
        cin >> teamIndex >> deltaPenalty;
        teamIndex--;

        treap.eraseOne(teams[teamIndex]);

        teams[teamIndex].acCount++;
        teams[teamIndex].penalty += deltaPenalty;

        treap.insert(teams[teamIndex]);

        cout << treap.indexOf(teams[0]) + 1 << "\n";
    }
}