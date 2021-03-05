#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Node {
    int val;
    Node *l, *r;
    Node() : l(0), r(0) {}
};

void dfs(Node *n, int sum, int &minSum, int &minLeaf) {
    sum += n->val;
    if (!n->l && !n->r) {
        if (sum < minSum || sum == minSum && n->val < minLeaf) {
            minSum = sum;
            minLeaf = n->val;
        }
    } else {
        if (n->l)
            dfs(n->l, sum, minSum, minLeaf);
        if (n->r)
            dfs(n->r, sum, minSum, minLeaf);
    }
}

void reconstruct(Node *n, vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr) {
    n->val = postorder[pr];
    if (pl != pr) {
        int im = find(inorder.begin() + il, inorder.begin() + ir, postorder[pr]) - inorder.begin();
        if (il < im)
            reconstruct(n->l = new Node(), inorder, il, im - 1, postorder, pl, pl + im - il - 1);
        if (im < ir)
            reconstruct(n->r = new Node(), inorder, im + 1, ir, postorder, pl + im - il, pr - 1);
    }
}

vector<int> read() {
    vector<int> v;
    while (1) {
        v.emplace_back();
        if (!(cin >> v.back()))
            return {};
        if (cin.peek() == '\n')
            break;
    }
    return v;
}

bool solve() {
    vector<int> inorder = read();
    vector<int> postorder = read();
    
    if (inorder.empty())
        return 0;

    Node n;
    reconstruct(&n, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    int minSum = 1e9, minLeaf = 1e9;
    dfs(&n, 0, minSum, minLeaf);

    cout << minLeaf << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}