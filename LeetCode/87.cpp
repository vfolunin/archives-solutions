class Solution {
    bool identical(string &a, string &b, int size, int aFrom, int bFrom,
                   vector<vector<vector<int>>> &memo) {
        int &res = memo[size][aFrom][bFrom];
        if (res != -1)
            return res;
        
        string sa = a.substr(aFrom, size);
        string sb = b.substr(bFrom, size);
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        return res = sa == sb;
    }
    
    bool canScramble(string &a, string &b, int size, int aFrom, int bFrom,
                     vector<vector<vector<int>>> &memoI, vector<vector<vector<int>>> &memoS) {
        int &res = memoS[size][aFrom][bFrom];
        if (res != -1)
            return res;
        
        if (size == 1)
            return res = a[aFrom] == b[bFrom];
        
        for (int aSize = 1, bSize = size - 1; aSize < size; aSize++, bSize--) {
            if (identical(a, b, aSize, aFrom, bFrom, memoI) &&
                identical(a, b, bSize, aFrom + aSize, bFrom + aSize, memoI) &&
                canScramble(a, b, aSize, aFrom, bFrom, memoI, memoS) &&
                canScramble(a, b, bSize, aFrom + aSize, bFrom + aSize, memoI, memoS))
                return res = 1;

            if (identical(a, b, aSize, aFrom, bFrom + bSize, memoI) &&
                identical(a, b, bSize, aFrom + aSize, bFrom, memoI) &&
                canScramble(a, b, aSize, aFrom, bFrom + bSize, memoI, memoS) &&
                canScramble(a, b, bSize, aFrom + aSize, bFrom, memoI, memoS))
                return res = 1;
        }
        
        return res = 0;
    }
    
public:
    bool isScramble(string &a, string &b) {
        int size = a.size();
        vector<vector<vector<int>>> memoI(size + 1, vector<vector<int>>(size, vector<int>(size, -1)));
        vector<vector<vector<int>>> memoS = memoI;
        return canScramble(a, b, size, 0, 0, memoI, memoS);
    }
};