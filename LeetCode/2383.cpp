class Solution {    
public:
    int minNumberOfHours(int energy, int exp, vector<int> &enemyEnergy, vector<int> &enemyExp) {
        int res = 0;
        
        for (int i = 0; i < enemyEnergy.size(); i++) {
            if (energy <= enemyEnergy[i]) {
                res += enemyEnergy[i] + 1 - energy;
                energy = enemyEnergy[i] + 1;
            }
            if (exp <= enemyExp[i]) {
                res += enemyExp[i] + 1 - exp;
                exp = enemyExp[i] + 1;
            }
            energy -= enemyEnergy[i];
            exp += enemyExp[i];
        }
        
        return res;
    }
};