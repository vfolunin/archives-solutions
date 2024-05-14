void rec(TreeNode *n, int &depth, int &balanced) {
    if (!n) {
        depth = 0;
        balanced = 1;
        return;
    }

    int lDepth, lBalanced, rDepth, rBalanced;
    rec(n->left, lDepth, lBalanced);
    rec(n->right, rDepth, rBalanced);

    depth = 1 + max(lDepth, rDepth);
    balanced = lBalanced && rBalanced && abs(lDepth - rDepth) <= 1; 
}

bool isBalanced(TreeNode *n) {
    int depth, balanced;
    rec(n, depth, balanced);
    return balanced;
}
