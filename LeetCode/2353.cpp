class FoodRatings {
    unordered_map<string, set<pair<int, string>>> values;
    unordered_map<string, string> cuisineOf;
    unordered_map<string, int> ratingOf;
    
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; i < foods.size(); i++) {
            values[cuisines[i]].insert({ -ratings[i], foods[i] });
            cuisineOf[foods[i]] = cuisines[i];
            ratingOf[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(const string &food, int newRating) {
        values[cuisineOf[food]].erase({ -ratingOf[food], food });
        ratingOf[food] = newRating;
        values[cuisineOf[food]].insert({ -ratingOf[food], food });
    }
    
    string highestRated(const string &cuisine) {
        return values[cuisine].begin()->second;
    }
};