class Solution {
public:
    bool isPreorder(vector<vector<int>> &nodes) {
        vector<int> stack = { nodes[0] };

        for (int i = 1; i < nodes.size(); i++) {
            while (!stack.empty() && stack.back() != nodes[i][1])
                stack.pop_back();

            if (stack.empty())
                return 0;
            
            stack.push_back(nodes[i][0]);
        }

        return 1;
    }
};