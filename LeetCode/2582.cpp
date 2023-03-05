class Solution {
public:    
    int passThePillow(int n, int time) {
        time %= (n - 1) * 2;
        
        if (time < n - 1)
            return time + 1;
        else
            return 2 * n - 1 - time;
    }
};