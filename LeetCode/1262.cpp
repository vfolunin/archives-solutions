class Solution {
public:
    int maxSumDivThree(vector<int> &a) {
        vector<int> res = { 0, -1, -1 };
        
        for (int value : a) {
            vector<int> nextRes = res;
            
            for (int i = 0; i < 3; i++) {
                if (res[i] != -1) {
                    int nextI = (i + value) % 3;
                    nextRes[nextI] = max(nextRes[nextI], res[i] + value);
                }
            }
            
            res.swap(nextRes);
        }
        
        return res[0];
    }
};