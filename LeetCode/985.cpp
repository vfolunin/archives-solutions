class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &values, vector<vector<int>> &queries) {
        int evenSum = 0;
        for (int value : values)
            if (value % 2 == 0)
                evenSum += value;
        
        vector<int> res;
        
        for (vector<int> &query : queries) {
            if (values[query[1]] % 2 == 0)
                evenSum -= values[query[1]];
            
            values[query[1]] += query[0];
            
            if (values[query[1]] % 2 == 0)
                evenSum += values[query[1]];
            
            res.push_back(evenSum);
        }
        
        return res;
    }
};