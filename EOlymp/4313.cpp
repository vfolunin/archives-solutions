#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct PersistentStack {
    struct Node {
        int value;
        Node *next;

        Node(int value, Node *next) : value(value), next(next) {}
    };

    vector<Node *> versions;

    PersistentStack() : versions(1) {}

    void push(int version, int value) {
        versions.push_back(new Node(value, versions[version]));
    }

    int pop(int v) {
        versions.push_back(versions[v]->next);
        return versions[v]->value;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    PersistentStack stack;

    for (int i = 0; i < opCount; i++) {
        int version, value;
        cin >> version >> value;

        if (value)
            stack.push(version, value);
        else
            cout << stack.pop(version) << "\n";
    }
}