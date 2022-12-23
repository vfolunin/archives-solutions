#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

class Treap {
    struct Node {
        int key, priority, value;
        Node *left = 0, *right = 0;
        Node(int key, int priority, int value) :
            key(key), priority(priority), value(value) {}
    } *root = 0;

    vector<Node *> stack;

    void fillTriplets(Node *n, int p, vector<vector<int>> &triplets) {
        if (triplets.size() <= n->value)
            triplets.resize(n->value + 1);
        triplets[n->value] = { p, n->left ? n->left->value : 0, n->right ? n->right->value : 0 };
        if (n->left)
            fillTriplets(n->left, n->value, triplets);
        if (n->right)
            fillTriplets(n->right, n->value, triplets);
    }

public:
    void push_back(int key, int priority, int value) {
        Node *n = new Node(key, priority, value);
        while (!stack.empty() && stack.back()->priority < n->priority) {
            n->left = stack.back();
            stack.pop_back();
        }
        if (stack.empty())
            root = n; 
        else
            stack.back()->right = n;
        stack.push_back(n);
    }

    void print() {
        vector<vector<int>> triplets;
        fillTriplets(root, 0, triplets);
        for (vector<int> &triplet : triplets) {
            for (int value : triplet)
                cout << value << " ";
            cout << "\n";
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<tuple<int, int, int>> triplets(size);
    for (int i = 0; i < triplets.size(); i++) {
        auto &[key, priority, index] = triplets[i];
        cin >> key >> priority;
        priority *= -1;
        index = i + 1;
    }

    sort(triplets.begin(), triplets.end());

    Treap treap;
    for (auto &[key, priority, index] : triplets)
        treap.push_back(key, priority, index);

    cout << "YES";
    treap.print();
}