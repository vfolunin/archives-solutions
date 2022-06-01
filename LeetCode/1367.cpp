class Solution {
    bool isPath(ListNode *head, TreeNode *root) {
        if (!head)
            return 1;
        
        if (!root)
            return 0;
        
        if (head->val != root->val)
            return 0;
            
        return isPath(head->next, root->left) || isPath(head->next, root->right);
    }
    
public:
    bool isSubPath(ListNode *head, TreeNode *root) {       
        if (!head)
            return 1;
        
        if (!root)
            return 0;
        
        if (isPath(head, root))
            return 1;
            
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};