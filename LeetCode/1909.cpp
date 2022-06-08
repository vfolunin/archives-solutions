class Solution {
    bool isIncreasing(const vector<int> &a) {
        for (int i = 0; i + 1 < a.size(); i++)
            if (a[i] >= a[i + 1])
                return 0;
        return 1;
    }
    
public:
    bool canBeIncreasing(vector<int> &a) {
        for (int i = 0; i + 1 < a.size(); i++) {
            if (a[i] >= a[i + 1]) {
                vector<int> b = a;
                a.erase(a.begin() + i);
                b.erase(b.begin() + i + 1);
                return isIncreasing(a) || isIncreasing(b);
            }
        }
        return 1;
    }
};