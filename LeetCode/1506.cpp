class Solution {
public:
    Node *findRoot(vector<Node *> &tree) {
        unordered_set<Node *> nodes(tree.begin(), tree.end());
        for (Node *n : tree)
            for (Node *child : n->children)
                nodes.erase(child);
        return *nodes.begin();
    }
};