class ThroneInheritance {
    unordered_map<string, vector<string>> tree;
    unordered_set<string> dead;
    string root;
    
    void traverse(string &v, vector<string> &res) {
        if (!dead.count(v))
            res.push_back(v);
        for (string &to : tree[v])
            traverse(to, res);
    }
    
public:
    ThroneInheritance(string kingName) : root(kingName) {}
    
    void birth(string parentName, string childName) {
        tree[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        traverse(root, res);
        return res;
    }
};