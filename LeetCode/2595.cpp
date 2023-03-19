class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2);
               
        for (int i = 0; i < 20; i++)
            if (n & (1 << i))
                res[i % 2]++;
        
        return res;
    }
};