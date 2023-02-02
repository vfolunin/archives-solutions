class Solution {
public:
    int missingNumber(vector<int> &a) {
        int delta = (a.back() - a.front()) / (int)a.size();
        if (!delta)
            return a[0];

        for (int i = 0; i < a.size(); i++)
            if (a[i] != a[0] + i * delta)
                return a[0] + i * delta;
                
        return -1;
    }
};