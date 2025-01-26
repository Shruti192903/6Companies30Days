//Count Collisions on a Road

class Solution {
public:
    int countCollisions(string dir) {
    int n = dir.size();
    stack<char> s;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(s.empty()) s.push(dir[i]);
        else if( (s.top() == 'S') && (dir[i] == 'L')) ans++;
        else if(s.top() == 'R' && (dir[i] == 'L')) {
            s.pop();
            dir[i] = 'S';
            i--;
            ans += 2;
        }
        else if( (s.top() == 'R') && (dir[i] == 'S')){
            s.pop();
            dir[i] = 'S';
            i--;
            ans++;
        }
        else{
            s.push(dir[i]);
        }
    }
    return ans;
}
};

/*
 * Definition:
 * The problem involves counting how many collisions occur between cars 
 * represented by a string where each character indicates a direction:
 * - 'L' for left, 
 * - 'R' for right, 
 * - 'S' for straight.
 *
 * Approach:
 * - Use a stack to keep track of the current state of car directions.
 * - Iterate through each character in the string and handle collision 
 *   cases based on the rules provided.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the length of the input string. 
 *   Each character is processed once.
 * - Space Complexity: O(n), in the worst case if all characters are pushed onto the stack.
 */
