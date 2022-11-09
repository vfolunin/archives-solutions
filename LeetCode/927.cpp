class Solution {
public:
    vector<int> threeEqualParts(vector<int> &a) {
        vector<int> onePos;
        for (int i = 0; i < a.size(); i++)
            if (a[i] == 1)
                onePos.push_back(i);
        
        if (onePos.empty())
            return { 0, 2 };
        
        if (onePos.size() % 3)
            return { -1, -1 };
        
        int resOnes = onePos.size() / 3;
        for (int i = 1; i < resOnes; i++)
            if (onePos[i] - onePos[i - 1] != onePos[resOnes + i] - onePos[resOnes + i - 1] ||
                onePos[i] - onePos[i - 1] != onePos[resOnes * 2 + i] - onePos[resOnes * 2 + i - 1])
                return { -1, -1 };
        
        int trailingZeros = a.size() - 1 - onePos.back();
        if (onePos[resOnes] - onePos[resOnes - 1] - 1 < trailingZeros ||
            onePos[resOnes * 2] - onePos[resOnes * 2 - 1] - 1 < trailingZeros)
            return { -1, -1 };
        
        return { onePos[resOnes - 1] + trailingZeros, onePos[resOnes * 2 - 1] + trailingZeros + 1 };
    }
};