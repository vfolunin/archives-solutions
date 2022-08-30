class Solution {
public:
    bool validPartition(vector<int> &a) {
        vector<int> can(a.size() + 1);
        can[0] = 1;
        can[2] = a[0] == a[1];
        
        for (int i = 3; i <= a.size(); i++) {
            if (a[i - 2] == a[i - 1])
                can[i] |= can[i - 2];            
            if (a[i - 3] == a[i - 2] && a[i - 2] == a[i - 1])
                can[i] |= can[i - 3];            
            if (a[i - 3] + 1 == a[i - 2] && a[i - 2] + 1 == a[i - 1])
                can[i] |= can[i - 3];
        }
        
        return can.back();
    }
};