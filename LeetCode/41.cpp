class Solution {
public:
    int firstMissingPositive(vector<int> &a) {
        for (int i = 0; i < a.size(); i++)
            while (1 <= a[i] && a[i] <= a.size() && a[i] != a[a[i] - 1])
                swap(a[i], a[a[i] - 1]);
        
        for (int i = 0; i < a.size(); i++)
            if (a[i] != i + 1)
                return i + 1;
        
        return a.size() + 1;
    }
};