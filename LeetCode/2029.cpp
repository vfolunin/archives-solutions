class Solution {    
public:
    bool stoneGameIX(vector<int> &a) {
        vector<int> modCount(3);
        for (int value : a)
            modCount[value % 3]++;
        
        if (modCount[0] % 2)
            return abs(modCount[1] - modCount[2]) > 2;
        else
            return modCount[1] && modCount[2];
    }
};