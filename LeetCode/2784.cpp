class Solution {
public:
    bool isGood(vector<int> &a) {
        sort(a.begin(), a.end());

        for (int i = 0; i < a.size(); i++)
            if (a[i] != min<int>(i + 1, a.size() - 1))
                return 0;
                
        return 1;
    }
};