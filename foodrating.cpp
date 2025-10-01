#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class FoodRatings {
    unordered_map<string, string> foodToCuisine;    // food -> cuisine
    unordered_map<string, int> foodToRating;        // food -> rating
    unordered_map<string, set<pair<int, string>>> cuisineToFoods; 
    // cuisine -> set of (-rating, food)

public:
    // Constructor
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    // Change the rating of a food
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        // Remove old entry and insert updated one
        cuisineToFoods[cuisine].erase({-oldRating, food});
        cuisineToFoods[cuisine].insert({-newRating, food});

        foodToRating[food] = newRating; // update in map
    }

    // Return highest rated food for a cuisine
    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->second; 
    }
};

int main() {
    // Example input
    vector<string> foods = {"githeri", "choma", "mandazi", "pilau", "matumbo", "chipo"};
    vector<string> cuisines = {"main dishn", "snack", "snack", "lunch", "snack", "main dishn"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings fr(foods, cuisines, ratings);

    cout << fr.highestRated("main dishn") << endl;   // githeri
    cout << fr.highestRated("snack") << endl; // matumbo

    fr.changeRating("sushi", 16);
    cout << fr.highestRated("snack") << endl; // sushi

    fr.changeRating("matumbo", 16);
    cout << fr.highestRated("snack") << endl; // matumbo

    return 0;
}