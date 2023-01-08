class Solution {
    vector<int> getCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        return count;
    }

    int getNonZeroCount(vector<int> &a) {
        return count_if(a.begin(), a.end(), [](int value) { return value; });
    }

public:
    bool isItPossible(string &a, string &b) {
        vector<int> aCount = getCount(a);
        vector<int> bCount = getCount(b);
        
        for (int ai = 0; ai < aCount.size(); ai++) {
            if (!aCount[ai])
                continue;

            for (int bi = 0; bi < bCount.size(); bi++) {
                if (!bCount[bi])
                    continue;
                
                aCount[ai]--;
                aCount[bi]++;
                bCount[ai]++;
                bCount[bi]--;

                if (getNonZeroCount(aCount) == getNonZeroCount(bCount))
                    return 1;
                
                aCount[ai]++;
                aCount[bi]--;
                bCount[ai]--;
                bCount[bi]++;
            }
        }
        
        return 0;
    }
};