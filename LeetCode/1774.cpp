class Solution {
    void rec(vector<int> &bases, vector<int> &toppings, int index, int sum, int targetSum, int &resSum) {
        if (index == toppings.size()) {
            if (abs(resSum - targetSum) > abs(sum - targetSum) ||
                abs(resSum - targetSum) == abs(sum - targetSum) && resSum > sum)
                resSum = sum;
            return;
        }
        
        if (index == -1) {
            for (int base : bases)
                rec(bases, toppings, index + 1, sum + base, targetSum, resSum);
        } else {
            for (int amount = 0; amount <= 2; amount++)
                rec(bases, toppings, index + 1, sum + toppings[index] * amount, targetSum, resSum);
        }
    }
    
public:
    int closestCost(vector<int> &bases, vector<int> &toppings, int targetSum) {
        int resSum = -1e9;
        rec(bases, toppings, -1, 0, targetSum, resSum);
        return resSum;
    }
};