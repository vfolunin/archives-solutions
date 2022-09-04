class Solution {    
public:
    int longestWPI(vector<int> &a) {
        int balance = 0, res = 0;
        unordered_map<int, int> firstPos;
        
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > 8)
                balance++;
            else
                balance--;
            
            if (balance > 0)
                res = i + 1;
            else if (firstPos.count(balance - 1))
                res = max(res, i - firstPos[balance - 1]);
            
            if (!firstPos.count(balance))
                firstPos[balance] = i;
        }
        
        return res;
    }
};