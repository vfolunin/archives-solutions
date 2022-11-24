class Solution {
    vector<int> oddPalindromes(string &s) {
        vector<int> res(s.size());
        for (int i = 0, l = 0, r = -1; i < s.size(); i++) {
            int k = (i > r ? 1 : min(res[l + r - i], r - i));
            while (i - k >= 0 && i + k < s.size() && s[i - k] == s[i + k])
                k++;
            res[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        return res;
    }
    
public:
    long long maxProduct(string &s) {
        vector<int> p = oddPalindromes(s);
        
        vector<int> l(s.size());
        deque<int> centers;
        for (int i = 0; i < s.size(); i++) {
            while (!centers.empty() && centers.front() + p[centers.front()] <= i)
                centers.pop_front();
            centers.push_back(i);
            
            l[i] = i - centers.front() + 1;
            if (i)
                l[i] = max(l[i], l[i - 1]);
        }
        
        vector<int> r(s.size());
        centers.clear();
        for (int i = s.size() - 1; i >= 0; i--) {
            while (!centers.empty() && centers.front() - p[centers.front()] >= i)
                centers.pop_front();
            centers.push_back(i);
            
            r[i] = centers.front() - i + 1;
            if (i + 1 < s.size())
                r[i] = max(r[i], r[i + 1]);
        }
        
        long long res = 0;
        for (int i = 0; i + 1 < s.size(); i++)
            res = max(res, (l[i] * 2LL - 1) * (r[i + 1] * 2LL - 1));
        return res;
    }
};