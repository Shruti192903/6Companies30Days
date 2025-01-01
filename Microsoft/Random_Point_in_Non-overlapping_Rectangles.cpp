// Random Point in Non-overlapping Rectangles

class Solution {
public:

    vector<int> cumulativeArea; // Areas of rectangles
    vector<vector<int>> rectangles; // List of inputs  
    int calculateArea(const vector<int>& rect){
        return (rect[2]-rect[0]+1) * (rect[3]-rect[1]+1); // Area
    }
    Solution(vector<vector<int>>& rects) {
        rectangles = rects;
        int totalArea =0;
        for( const auto &rect: rectangles){
            totalArea += calculateArea(rect);
            cumulativeArea.push_back(totalArea);
        }
    }
    
    // Pick a random point from one of the rectangles
    vector<int> pick() {
        int randomArea = rand() % cumulativeArea.back(); // Random number in total area
        int rect_Indx = upper_bound(cumulativeArea.begin(), cumulativeArea.end(), randomArea) - cumulativeArea.begin() ; //Binary Search
        const auto& selected_rect = rectangles[rect_Indx];
        int randomX = rand() % (selected_rect[2] - selected_rect[0]+ 1)+selected_rect[0];
        int randomY = rand() % (selected_rect[3] - selected_rect[1]+ 1)+selected_rect[1];
        return {randomX, randomY};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */


/*
 * Problem Definition:
 * Given a list of non-overlapping axis-aligned rectangles represented by their 
 * bottom-left and top-right corners, design an algorithm to pick a random integer 
 * point inside the space covered by one of the given rectangles. A point on the 
 * perimeter of a rectangle is included in the space covered by that rectangle.
 * 
 * Each integer point inside the space covered by one of the rectangles should be 
 * equally likely to be returned.
 */
/*
 * Approach:
 * 1. Store the input rectangles and calculate their areas.
 * 2. Maintain a cumulative area array to facilitate weighted random selection.
 * 3. When picking a point:
 *   - Generate a random number in the range of total area.
 *   - Use binary search to find which rectangle corresponds to this random number.
 *   - Generate a random point within that rectangle's bounds.
 *
 * Complexity Analysis:
 * - Time Complexity:
 *   - Constructor: O(n) where n is the number of rectangles (for calculating areas).
 *   - pick(): O(log n) due to binary search on cumulative areas.
 *
 * - Space Complexity: O(n) for storing rectangles and cumulative areas.
 */
