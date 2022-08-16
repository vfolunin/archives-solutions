class Solution {
public:
    int maxTurbulenceSize(vector<int> &a) {
        vector<int> up(a.size(), 1), down(a.size(), 1);
        
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] < a[i])
                up[i] = down[i - 1] + 1;
            else if (a[i - 1] > a[i])
                down[i] = up[i - 1] + 1;
        }
        
        return max(*max_element(up.begin(), up.end()), *max_element(down.begin(), down.end()));
    }
};