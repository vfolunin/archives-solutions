class Solution {
    vector<int> makeNumber(vector<int> &a, int size) {
        vector<int> stack;
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && stack.back() < a[i] && stack.size() + a.size() - 1 - i >= size)
                stack.pop_back();
            if (stack.size() < size)
                stack.push_back(a[i]);
        }
        return stack;
    }
    
    bool aIsBigger(const vector<int> &a, int ai, const vector<int> &b, int bi) {
        for ( ; ai < a.size() && bi < b.size(); ai++, bi++)
            if (a[ai] != b[bi])
                return a[ai] > b[bi];
        return ai < a.size();
    }
    
    vector<int> mergeNumbers(const vector<int> &a, const vector<int> &b) {
        vector<int> res(a.size() + b.size());
        for (int i = 0, ai = 0, bi = 0; i < res.size(); i++) {
            if (bi == b.size() || ai < a.size() && aIsBigger(a, ai, b, bi))
                res[i] = a[ai++];
            else
                res[i] = b[bi++];
        }
        return res;
    }
    
public:
    vector<int> maxNumber(vector<int> &a, vector<int> &b, int size) {
        vector<int> res;
        for (int aSize = 0, bSize = size; aSize <= size; aSize++, bSize--)
            if (aSize <= a.size() && bSize <= b.size())
                res = max(res, mergeNumbers(makeNumber(a, aSize), makeNumber(b, bSize)));
        return res;
    }
};