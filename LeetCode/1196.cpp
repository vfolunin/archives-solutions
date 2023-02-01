class Solution {
public:
    int maxNumberOfApples(vector<int> &a) {
        sort(a.begin(), a.end());

        int count = 0, sum = 0;
        for (int value : a) {
            if (sum + value <= 5000) {
                sum += value;
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};