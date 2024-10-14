#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct PersistentStack {
    struct Node {
        int val, size;
        Node *next;

        static int getSize(Node *n) {
            return n ? n->size : 0;
        }

        Node(int val, Node *next) :
            val(val), size(val + getSize(next)), next(next) {}
    };

    vector<Node *> versions;
    long long totalSize = 0;

    PersistentStack() : versions(1) {}

    void push(int v, int val) {
        versions.push_back(new Node(val, versions[v]));
        totalSize += Node::getSize(versions.back());
    }

    void pop(int v) {
        versions.push_back(versions[v]->next);
        totalSize += Node::getSize(versions.back());
    }

    long long getTotalSize() {
        return totalSize;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    PersistentStack stack;

    for (int i = 0; i < opCount; i++) {
        int version, opType;
        cin >> version >> opType;

        if (opType)
            stack.push(version, opType);
        else
            stack.pop(version);
    }

    cout << stack.getTotalSize();
}