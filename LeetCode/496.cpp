class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &a, vector<int> &b) {
        vector<int> greater(b.size(), -1), stack;
        unordered_map<int, int> pos;
        
        for (int i = 0; i < b.size(); i++) {
            while (!stack.empty() && b[stack.back()] < b[i]) {
                greater[stack.back()] = b[i];
                stack.pop_back();
            }
            stack.push_back(i);
            
            pos[b[i]] = i;
        }
        
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            res[i] = greater[pos[a[i]]];
        return res;
    }
};