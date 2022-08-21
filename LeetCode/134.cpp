class Solution {
    int stop(vector<int> &gas, vector<int> &cost, int from) {
        int amount = 0;
        for (int i = 0; i < gas.size(); i++) {
            int j = (from + i) % gas.size();
            amount += gas[j];
            if (amount < cost[j])
                return (j + 1) % gas.size();
            amount -= cost[j];
        }
        return -1;
    }
    
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int from = 0;
        while (1) {
            int to = stop(gas, cost, from);
            if (to == -1)
                return from;
            if (to <= from)
                return -1;
            from = to;
        }
    }
};