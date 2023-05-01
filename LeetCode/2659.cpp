class ImplicitTreap {
    inline static minstd_rand gen;

    struct Node {
        int value, priority, size = 1, minValue, minIndex = 0;
        Node *left = 0, *right = 0;
        Node(int value) : value(value), priority(gen()), minValue(value) {}
    } *root = 0;

    int getSize(Node *n) {
        return n ? n->size : 0;
    }

    int getMinValue(Node *n) {
        return n ? n->minValue : 2e9;
    }

    int getMinIndex(Node *n) {
        return n ? n->minIndex : -1;
    }

    void update(Node *n) {
        if (n) {
            n->size = getSize(n->left) + 1 + getSize(n->right);
            n->minValue = min({ getMinValue(n->left), n->value, getMinValue(n->right) });
            if (n->minValue == getMinValue(n->left))
                n->minIndex = getMinIndex(n->left);
            else if (n->minValue == n->value)
                n->minIndex = getSize(n->left);
            else
                n->minIndex = getSize(n->left) + 1 + getMinIndex(n->right);
        }
    }

    Node *merge(Node *a, Node *b) {
        if (!a || !b)
            return a ? a : b;
        if (a->priority > b->priority) {
            a->right = merge(a->right, b);
            update(a);
            return a;
        } else {
            b->left = merge(a, b->left);
            update(b);
            return b;
        }
    }

    void split(Node *t, int k, Node *&a, Node *&b) {
        if (!t) {
            a = b = 0;
            return;
        }
        if (getSize(t->left) < k) {
            split(t->right, k - getSize(t->left) - 1, t->right, b);
            a = t;
        } else {
            split(t->left, k, a, t->left);
            b = t;
        }
        update(a);
        update(b);
    }

public:
    void pushBack(int value) {
        root = merge(root, new Node(value));
    }

    int getMinIndex() {
        return getMinIndex(root);
    }
    
    void rotate(int index) {
        Node *a, *b, *c;
        split(root, index, a, b);
        split(b, 1, b, c);
        root = merge(c, a);
    }
};

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int> &a) {
        ImplicitTreap treap;
        for (int value : a)
            treap.pushBack(value);
        
        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            int index = treap.getMinIndex();
            res += index + 1;
            treap.rotate(index);
        }
        return res;
    }
};