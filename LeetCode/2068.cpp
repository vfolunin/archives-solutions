class Solution {
    vector<int> getLetterCount(string &s) {
        vector<int> res(26);
        for (char c : s)
            res[c - 'a']++;
        return res;
    }
    
public:
    bool checkAlmostEquivalent(string a, string b) {
        vector<int> aLetterCount = getLetterCount(a);
        vector<int> bLetterCount = getLetterCount(b);
        
        for (int i = 0; i < aLetterCount.size(); i++)
            if (abs(aLetterCount[i] - bLetterCount[i]) > 3)
                return 0;
        
        return 1;
    }
};