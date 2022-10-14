class Solution {
    double getTime(vector<int> &a, vector<int> &b) {
        return (double)(b[0] - a[0]) / (a[1] - b[1]);
    }
    
public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars) {
        vector<double> res(cars.size(), 1e9);
        vector<int> stack;
        
        for (int i = cars.size() - 1; i >= 0; i--) {
            while (!stack.empty() && (cars[i][1] <= cars[stack.back()][1] ||
                   res[stack.back()] < getTime(cars[i], cars[stack.back()])))
                stack.pop_back();
            
            if (!stack.empty())
                res[i] = getTime(cars[i], cars[stack.back()]);
            
            stack.push_back(i);
        }
        
        for (double &time : res)
            if (time == 1e9)
                time = -1;
        
        return res;
    }
};