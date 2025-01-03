// Shopping Offers

#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <tuple>

using namespace std;

class Solution {
public:
    int shoppingOffers(const vector<int>& itemPrices, const vector<vector<int>>& specialOffers, const vector<int>& requiredItems) {
        // Use a memoization map to store already computed results
        unordered_map<string, int> memo;
        return shoppingOffersHelper(itemPrices, specialOffers, requiredItems, memo);
    }

private:
    int shoppingOffersHelper(const vector<int>& itemPrices, const vector<vector<int>>& specialOffers,
                             const vector<int>& requiredItems, unordered_map<string, int>& memo) {
        // Calculate the current state key for memoization
        string stateKey = getStateKey(requiredItems);
        
        // Check if we have already computed this state
        if (memo.find(stateKey) != memo.end()) {
            return memo[stateKey];
        }

        // Calculate the minimum cost without any offers
        int minimumCost = inner_product(itemPrices.begin(), itemPrices.end(), requiredItems.begin(), 0);

        // Iterate through each special offer
        for (const vector<int>& offer : specialOffers) {
            vector<int> remainingItems = calculateRemainingItems(requiredItems, offer);
            if (remainingItems.empty()) continue;

            // Calculate cost with the current offer applied
            minimumCost = min(minimumCost, offer.back() + shoppingOffersHelper(itemPrices, specialOffers, remainingItems, memo));
        }

        // Store the result in the memoization map and return it
        memo[stateKey] = minimumCost;
        return minimumCost;
    }

    string getStateKey(const vector<int>& requiredItems) {
        // Create a unique key for the current state based on required items
        string key;
        for (int item : requiredItems) {
            key += to_string(item) + ",";
        }
        return key;
    }

    vector<int> calculateRemainingItems(const vector<int>& requiredItems, const vector<int>& offer) {
        vector<int> remainingItems(requiredItems.size(), 0);
        for (int i = 0; i < requiredItems.size(); ++i) {
            if (offer[i] > requiredItems[i]) return {};
            remainingItems[i] = requiredItems[i] - offer[i];
        }
        return remainingItems;
    }
};



/**
     * Definition:
     * The shoppingOffers function calculates the minimum cost to satisfy 
     * a list of item needs given their individual prices and available 
     * special offers. Each special offer consists of a combination of 
     * items that can be purchased at a discounted price.
     *
     * Approach:
     * 1. Calculate the initial cost without any offers using the inner_product 
     *    function to multiply item prices by their respective needs.
     * 2. Iterate through each special offer:
     *    - Calculate the remaining items needed after applying the current offer.
     *    - If the offer can be applied (i.e., it does not exceed the required items), 
     *      recursively calculate the total cost using this offer.
     * 3. Update the minimum cost found by comparing it with the cost obtained 
     *    by applying each offer.
     *
     * Time Complexity:
     * The time complexity is O(m * n), where m is the number of special offers 
     * and n is the number of items. This is due to iterating through each offer 
     * and checking if it can be applied to the current needs, which involves 
     * iterating through all items.
     **/
