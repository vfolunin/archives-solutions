#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    char val;
    Node *l, *r;
    Node() : l(0), r(0) {}
};

void reconstruct(Node *n, vector<string> &layers, char l, char r) {
    while (layers.back().empty())
        layers.pop_back();
    n->val = layers.back().back();

    vector<string> layersL(layers.size() - 1), layersR(layers.size() - 1);
    int lSize = 0, rSize = 0;

    for (int i = 0; i + 1 < layers.size(); i++) {
        for (char c : layers[i]) {
            if (c < n->val) {
                layersL[i] += c;
                lSize++;
            } else {
                layersR[i] += c;
                rSize++;
            }
        }
    }

    if (lSize)
        reconstruct(n->l = new Node(), layersL, l, n->val - 1);
    if (rSize)
        reconstruct(n->r = new Node(), layersR, n->val + 1, r);
}

void preorder(Node *n) {
    if (!n)
        return;
    cout << n->val;
    preorder(n->l);
    preorder(n->r);
}

bool solve() {
    vector<string> layers;

    while (1) {
        string s;
        if (!(cin >> s))
            return 0;

        if (!isalpha(s[0]))
            break;

        layers.push_back(s);
    }

    Node *root = new Node();
    reconstruct(root, layers, 'A', 'Z');
    
    preorder(root);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}