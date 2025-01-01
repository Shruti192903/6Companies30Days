// Find the Winner of the Circular Game

class Solution {
public:

    int solve(int totalfrnds, int k){
        if(totalfrnds == 1){
            return 0; //If only 1 friend 
        }
        return ( solve(totalfrnds-1,k) + k ) % totalfrnds; //Adjustment for current, circular position
    }

    int findTheWinner(int totalfrnds, int k) {
        return solve(totalfrnds,k)+1 ;// For 0-based indexing
    }
};

/* Problem Statement:
 * There are `n` friends that are playing a game. The friends are sitting in a circle
 * and are numbered from `1` to `n` in clockwise order. The rules of the game are as follows:
 *
 * 1. Start at the 1st friend.
 * 2. Count the next `k` friends in the clockwise direction, including the friend you started at.
 * 3. The last friend you counted leaves the circle and loses the game.
 * 4. If there is still more than one friend in the circle, go back to step 2 starting from
 *    the friend immediately clockwise of the friend who just lost and repeat.
 * 5. Else, the last friend in the circle wins the game.
 *
 * Given the number of friends, `n`, and an integer `k`, return the winner of the game.
 *
 * Approach:
 * To determine the winner of the circular game:
 * 1. Use a recursive function to simulate the elimination process.
 * 2. Base Case: If there is only one friend left (`totalfrnds == 1`), return `0` (the index of that friend).
 * 3. Recursive Case: For more than one friend, calculate the position of the winner using:
 *    winner = (solve(totalfrnds - 1, k) + k) % totalfrnds
 * 4. In the main function, call this recursive function and adjust for zero-based indexing by adding `1`.
 */
