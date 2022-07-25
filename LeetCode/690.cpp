class Solution {
    int rec(unordered_map<int, Employee *> &tree, int v) {
        int res = tree[v]->importance;
        for (int to : tree[v]->subordinates)
            res += rec(tree, to);
        return res;
    }
    
public:
    int getImportance(vector<Employee *> &employees, int id) {
        unordered_map<int, Employee *> tree;
        for (Employee *employee : employees)
            tree[employee->id] = employee;
        return rec(tree, id);
    }
};