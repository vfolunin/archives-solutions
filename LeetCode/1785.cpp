class Solution {
public:
    int minElements(vector<int> &a, int limit, int goal) {
        long long sum = 0;
        for (int value : a)
            sum += value;
        
        sum = abs(sum - goal);
        return (sum + limit - 1) / limit;
    }
};