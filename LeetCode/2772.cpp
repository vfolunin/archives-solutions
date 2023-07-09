class Solution {
public:
    bool checkArray(vector<int> &a, int width) {
        vector<int> delta(a.size());
        int deltaSum = 0;

        for (int i = 0; i < a.size(); i++) {
            if (i >= width)
                deltaSum -= delta[i - width];
            
            if (a[i] < deltaSum)
                return 0;
            
            if (a[i] > deltaSum) {
                if (i + width - 1 >= a.size())
                    return 0;

                delta[i] = a[i] - deltaSum;
                deltaSum += delta[i];
            }
        }
        
        return 1;
    }
};