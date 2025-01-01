// Circle and Rectangle Overlapping

using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        x1 -= xCenter;
        x2 -= xCenter;
        y1 -= yCenter;
        y2 -= yCenter;

        int X_Closest = max(x1, min(0,x2));
        int Y_Closest = max(y1, min(0,y2));

        int squared_distance = X_Closest*X_Closest + Y_Closest*Y_Closest;

        return squared_distance <= radius*radius; //Overlap
    }
};


/*
 * Circle and Rectangle Overlapping
 *
 * Problem Statement:
 * Given a circle and a rectangle, determine whether the circle and rectangle overlap.
 * The circle is defined by its center and radius, while the rectangle is defined by its
 * bottom-left and top-right corners.
 *
 * Definitions:
 * - Circle: represented by its center coordinates (x_center, y_center) and radius r.
 * - Rectangle: defined by its bottom-left corner (x1, y1) and top-right corner (x2, y2).
 *
 * Example:
 * Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
 * Output: true
 * Explanation: The circle overlaps with the rectangle at point (1,0).
 *
 * Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 2, y1 = 2, x2 = 3, y2 = 3
 * Output: false
 * Explanation: The circle does not overlap with the rectangle.
 *
 * Approach:
 * To determine if the circle overlaps with the rectangle:
 * 1. Find the closest point on the rectangle to the center of the circle.
 * 2. Calculate the distance between this closest point and the center of the circle.
 * 3. If this distance is less than or equal to the radius of the circle, then they overlap.
 */

/*
 * Complexity Analysis:
 * - Time Complexity: O(1) - The solution involves a constant number of calculations.
 * - Space Complexity: O(1) - No additional space is used.
 *
 * Link to Full Problem Description:
 * For more details, visit [Circle and Rectangle Overlapping - LeetCode](https://leetcode.com/problems/circle-and-rectangle-overlapping/description/).
 */
