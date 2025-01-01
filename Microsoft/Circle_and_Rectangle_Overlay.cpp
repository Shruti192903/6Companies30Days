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
 */
