class Treap {
    inline static minstd_rand gen;

    struct Node {
        int key, priority, size = 1;
        long long sum;
        Node *left = 0, *right = 0;
        Node(int key) : key(key), priority(gen()), sum(key) {}
    } *root = 0;

    int getSize(Node *n) const {
        return n ? n->size : 0;
    }

    long long getSum(Node *n) const {
        return n ? n->sum : 0;
    }

    void update(Node *n) {
        if (n) {
            n->size = getSize(n->left) + 1 + getSize(n->right);
            n->sum = getSum(n->left) + n->key + getSum(n->right);
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

    void split(Node *t, int key, Node *&a, Node *&b) {
        if (!t) {
            a = b = 0;
            return;
        }
        if (t->key < key) {
            split(t->right, key, t->right, b);
            a = t;
        } else {
            split(t->left, key, a, t->left);
            b = t;
        }
        update(a);
        update(b);
    }

    void splitByIndex(Node *t, int index, Node *&a, Node *&b) {
        if (!t) {
            a = b = 0;
            return;
        }
        int leftSize = getSize(t->left);
        if (index <= leftSize) {
            splitByIndex(t->left, index, a, t->left);
            b = t;
        } else {
            splitByIndex(t->right, index - leftSize - 1, t->right, b);
            a = t;
        }
        update(a);
        update(b);
    }
    
public:
    void insert(int key) {
        Node *less, *greater;
        split(root, key, less, greater);
        root = merge(less, merge(new Node(key), greater));
    }

    void eraseOne(int key) {
        Node *less, *equal, *greater;
        split(root, key, less, equal);
        split(equal, key + 1, equal, greater);
        if (equal) 
            equal = merge(equal->left, equal->right);
        root = merge(less, merge(equal, greater));
    }

    long long getSum(int lIndex, int rIndex) {
        Node *less, *equal, *greater;
        splitByIndex(root, lIndex, less, equal);
        splitByIndex(equal, rIndex - lIndex + 1, equal, greater);
        long long sum = getSum(equal);
        root = merge(less, merge(equal, greater));
        return sum;
    }
};

class MKAverage {
    int size, lrSize;
    Treap treap;
    queue<int> q;
    
public:
    MKAverage(int size, int lrSize) : size(size), lrSize(lrSize) {}
    
    void addElement(int value) {
        treap.insert(value);
        q.push(value);
        
        if (q.size() > size) {
            treap.eraseOne(q.front());
            q.pop();
        }            
    }
    
    int calculateMKAverage() {
        if (q.size() < size)
            return -1;
        
        return treap.getSum(lrSize, size - 1 - lrSize) / (size - 2 * lrSize);
    }
};