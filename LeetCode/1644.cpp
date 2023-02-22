class Solution {
    void traverse(TreeNode *n, vector<TreeNode *> &nodes, int depth, vector<int> &depths) {
        if (!n)
            return;

        traverse(n->left, nodes, depth + 1, depths);

        nodes.push_back(n);
        depths.push_back(depth);

        traverse(n->right, nodes, depth + 1, depths);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *a, TreeNode *b) {
        vector<TreeNode *> nodes;
        vector<int> depths;
        traverse(root, nodes, 0, depths);

        int ai = find(nodes.begin(), nodes.end(), a) - nodes.begin();
        int bi = find(nodes.begin(), nodes.end(), b) - nodes.begin();
        if (ai == nodes.size() || bi == nodes.size())
            return 0;
        if (ai > bi)
            swap(ai, bi);
        
        int i = min_element(depths.begin() + ai, depths.begin() + bi + 1) - depths.begin();
        return nodes[i];
    }
};