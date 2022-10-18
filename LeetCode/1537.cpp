class Solution {
    long long aRec(int i, vector<int> &a, vector<int> &b,
                   unordered_map<int, int> &aPos, unordered_map<int, int> &bPos,
                   vector<long long> &aMemo, vector<long long> &bMemo) {
        long long &res = aMemo[i];
        if (res)
            return res;
        
        res = a[i];
        if (i)
            res = max(res, aRec(i - 1, a, b, aPos, bPos, aMemo, bMemo) + a[i]);
        if (bPos.count(a[i]) && bPos[a[i]])
            res = max(res, bRec(bPos[a[i]] - 1, a, b, aPos, bPos, aMemo, bMemo) + a[i]);
        return res;
    }
    
    long long bRec(int i, vector<int> &a, vector<int> &b,
                   unordered_map<int, int> &aPos, unordered_map<int, int> &bPos,
                   vector<long long> &aMemo, vector<long long> &bMemo) {
        long long &res = bMemo[i];
        if (res)
            return res;
        
        res = b[i];
        if (i)
            res = max(res, bRec(i - 1, a, b, aPos, bPos, aMemo, bMemo) + b[i]);
        if (aPos.count(b[i]) && aPos[b[i]])
            res = max(res, aRec(aPos[b[i]] - 1, a, b, aPos, bPos, aMemo, bMemo) + b[i]);
        return res;        
    }
    
public:
    int maxSum(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> aPos;
        for (int i = 0; i < a.size(); i++)
            aPos[a[i]] = i;
        
        unordered_map<int, int> bPos;
        for (int i = 0; i < b.size(); i++)
            bPos[b[i]] = i;
        
        vector<long long> aMemo(a.size());
        vector<long long> bMemo(b.size());
        
        long long aMax = aRec(a.size() -1, a, b, aPos, bPos, aMemo, bMemo);
        long long bMax = bRec(b.size() -1, a, b, aPos, bPos, aMemo, bMemo);
        const long long MOD = 1e9 + 7;
        
        return max(aMax, bMax) % MOD;
    }
};