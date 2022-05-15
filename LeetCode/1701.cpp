class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        int free = 0;
        double waitTime = 0;
        
        for (vector<int> &customer : customers) {
            free = max(free, customer[0]) + customer[1];
            waitTime += free - customer[0];
        }
        
        return waitTime / customers.size();
    }
};