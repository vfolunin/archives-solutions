class Solution {
public:
    int minOperations(vector<string> &ops) {
        int depth = 0;
        for (string &op : ops) {
            if (op == "../")
                depth = max(depth - 1, 0);
            else if (op != "./")
                depth++;
        }
        return depth;
    }
};