class Solution {
public:
    int findMaximizedCapital(int n, int capital, vector<int> &profit, vector<int> &threshold) {
        vector<pair<int, int>> projects(profit.size());
        for (int i = 0; i < projects.size(); i++)
            projects[i] = { threshold[i], profit[i] };
        sort(projects.begin(), projects.end());
        
        priority_queue<int> profits;
        
        for (int i = 0, pi = 0; i < n; i++) {
            while (pi < projects.size() && projects[pi].first <= capital) {
                profits.push(projects[pi].second);
                pi++;
            }
            
            if (profits.empty())
                break;
            
            capital += profits.top();
            profits.pop();
        }
        
        return capital;
    }
};