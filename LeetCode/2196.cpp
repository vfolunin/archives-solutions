class Solution {
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<int, TreeNode *> nodes;
        
        for (vector<int> &description : descriptions) {
            if (!nodes.count(description[0]))
                nodes[description[0]] = new TreeNode(description[0]);
            
            if (!nodes.count(description[1]))
                nodes[description[1]] = new TreeNode(description[1]);
            
            if (description[2])
                nodes[description[0]]->left = nodes[description[1]];
            else
                nodes[description[0]]->right = nodes[description[1]];
        }
        
        unordered_set<TreeNode *> rootCandidates;
        
        for (auto &[key, node] : nodes)
            rootCandidates.insert(node);
        
        for (auto &[key, node] : nodes) {
            rootCandidates.erase(node->left);
            rootCandidates.erase(node->right);
        }
        
        return *rootCandidates.begin();
    }
};