class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int> &asteroids) {
        sort(asteroids.begin(), asteroids.end());
        
        for (int asteroid : asteroids) {
            if (mass >= asteroid)
                mass += asteroid;
            else
                return 0;
        }
        
        return 1;
    }
};