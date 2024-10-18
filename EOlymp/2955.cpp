#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct PersistentArray {
    struct Node {
        int value;
        Node *l, *r;

        Node(int value = 0, Node *l = 0, Node *r = 0) : value(value), l(l), r(r) {}
    };
    vector<Node *> versions;
    int size;

    Node *build(int vl, int vr, vector<int> &a) {
        Node *n = new Node;
        if (vl == vr) {
            n->value = a[vl];
            return n;
        }
        int vm = vl + (vr - vl) / 2;
        n->l = build(vl, vm, a);
        n->r = build(vm + 1, vr, a);
        return n;
    }

    int get(Node *n, int vl, int vr, int index) {
        if (vl == vr)
            return n->value;
        int vm = vl + (vr - vl) / 2;
        if (index <= vm)
            return get(n->l, vl, vm, index);
        else
            return get(n->r, vm + 1, vr, index);
    }

    Node *set(Node *n, int vl, int vr, int index, int value) {
        if (vl == vr)
            return new Node(value);
        int vm = vl + (vr - vl) / 2;
        if (index <= vm)
            return new Node(0, set(n->l, vl, vm, index, value), n->r);
        else
            return new Node(0, n->l, set(n->r, vm + 1, vr, index, value));
    }

    PersistentArray(vector<int> &a) : size(a.size()) {
        versions.push_back(build(0, size - 1, a));
    }

    int get(int version, int index) {
        return get(versions[version], 0, size - 1, index);
    }

    void set(int version, int index, int value) {
        versions.push_back(set(versions[version], 0, size - 1, index, value));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    PersistentArray persistentArray(a);

    int opCount;
    cin >> opCount;

    for (int i = 0; i < opCount; i++) {
        string type;
        int version, index;
        cin >> type >> version >> index;
        version--;
        index--;

        if (type == "create") {
            int value;
            cin >> value;

            persistentArray.set(version, index, value);
        } else {
            cout << persistentArray.get(version, index) << "\n";
        }
    }
}