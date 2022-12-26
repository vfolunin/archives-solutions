class Solution {
public:
    int closetTarget(vector<string> &a, string target, int from) {
        int res1 = 0;
        while (res1 < a.size() && a[(from + res1) % a.size()] != target)
            res1++;

        if (res1 == a.size())
            return -1;
        
        int res2 = 0;
        while (a[(from + a.size() - res2) % a.size()] != target)
            res2++;
        
        return min(res1, res2);
    }
};