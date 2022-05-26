class Solution {
public:
    double trimMean(vector<int> &a) {
        sort(a.begin(), a.end());
        int margin = a.size() / 20;
        
        double sum = 0;
        for (int i = margin; i + margin < a.size(); i++)
            sum += a[i];
        return sum / (a.size() - 2 * margin);
    }
};