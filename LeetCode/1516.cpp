class Solution {
    Node *getParent(Node *n, Node *child) {
        if (!n)
            return 0;

        for (Node *to : n->children) {
            if (to == child) 
                return n;
            if (Node *parent = getParent(to, child); parent)
                return parent;
        }

        return 0;
    }

    bool contains(Node *n, Node *child) {
        if (!n)
            return 0;
        
        for (Node *to : n->children)
            if (to == child || contains(to, child))
                return 1;
        
        return 0;
    }

public:
    Node *moveSubTree(Node *root, Node *a, Node *b) {
        if (find(b->children.begin(), b->children.end(), a) != b->children.end())
            return root;

        Node *ap = getParent(root, a);
        Node *bp = getParent(root, b);

        if (!ap) {
            bp->children.erase(find(bp->children.begin(), bp->children.end(), b));
            b->children.push_back(a);
            return b;
        }
    
        if (contains(a, b)) {
            bp->children.erase(find(bp->children.begin(), bp->children.end(), b));
            b->children.push_back(a);
            *find(ap->children.begin(), ap->children.end(), a) = b;
        } else {
            ap->children.erase(find(ap->children.begin(), ap->children.end(), a));
            b->children.push_back(a);
        }

        return root;
    }
};