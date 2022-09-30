class Treap {
    inline static minstd_rand gen;
    
    struct Node {
        int key, priority, value, minValue;
        Node *left = 0, *right = 0;
        Node(int key, int value) : key(key), priority(gen()), value(value), minValue(value) {}
    } *root = 0;
    
    int getMinValue(Node *n) const {
        return n ? n->minValue : 1e9;
    }
    
    void update(Node *n) {
        if (n)
            n->minValue = min({ getMinValue(n->left), n->value, getMinValue(n->right) });
    }
    
    Node *merge(Node *a, Node *b) {
        if (!a || !b) {
            return a ? a : b;
        }
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
    
public:
    void insert(int key, int value) {
        Node *a, *b;
        split(root, key, a, b);
        root = merge(a, merge(new Node(key, value), b));
    }
    
    void erase(int key) {
        Node *a, *b, *c;
        split(root, key, a, b);
        split(b, key + 1, b, c);
        root = merge(a, c);
    }
    
    int getMinValue(int key) {
        Node *a, *b;
        split(root, key, a, b);
        int res = getMinValue(b);
        root = merge(a, b);
        return res;
    }
};

struct Event {
    int x, i;
    enum { BEGIN, POINT, END } type;
    
    bool operator < (const Event &that) const {
        if (x != that.x)
            return x < that.x;
        if (type != that.type)
            return type < that.type;
        return i < that.i;
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        set<Event> events;
        for (int i = 0; i < intervals.size(); i++) {
            events.insert({ intervals[i][0], i, Event::BEGIN });
            events.insert({ intervals[i][1], i, Event::END });
        }
        for (int i = 0; i < queries.size(); i++)
            events.insert({ queries[i], i, Event::POINT });
        
        Treap treap;
        vector<int> res(queries.size());
        
        for (auto &[x, i, type] : events) {
            if (type == Event::BEGIN) {
                treap.insert(intervals[i][1], intervals[i][1] - intervals[i][0] + 1);
            } else if (type == Event::END) {
                treap.erase(intervals[i][1]);
            } else {
                res[i] = treap.getMinValue(x);
                if (res[i] == 1e9)
                    res[i] = -1;
            }
        }
        
        return res;
    }
};