class Solution {
public:
    int minCost(vector<int> &start, vector<int> &finish, vector<int> &rowCost, vector<int> &colCost) {
        int res = 0;
        
        while (start[0] != finish[0]) {
            start[0] += start[0] < finish[0] ? 1 : -1;
            res += rowCost[start[0]];
        }
        
        while (start[1] != finish[1]) {
            start[1] += start[1] < finish[1] ? 1 : -1;
            res += colCost[start[1]];
        }
        
        return res;
    }
};