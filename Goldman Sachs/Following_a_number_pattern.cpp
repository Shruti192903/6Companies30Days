//Following a number pattern

class Solution{
public:
 string printMinNumberForPattern(string S){
        int n=S.size();
        string initial;
        for(char i='1';i<='1'+n;i++){
            initial.push_back(i);
        }
        // cout<<initial<<endl;
        int j=0;
        int i=0;
        while(i<n){
            if(S[i]=='I') {j++; i++;}
            else{
            int D=j;
            // int cnt=0;
            while (i<n&&S[i]=='D'){
                i++;
                j++;
                
            }
            reverse(initial.begin()+D,initial.begin()+j+1);
            }
            
        }
         return initial;
    }
};

/* Definition:
 * This function constructs the smallest number possible by rearranging 
 * digits according to the specified increasing and decreasing patterns.
 *
 * Approach:
 * - Start with an initial string containing digits from '1' to 'n+1', where 
 *   n is the length of the pattern.
 * - Traverse through the pattern:
 *   - For each 'I', move to the next character.
 *   - For each 'D', continue moving until you reach an 'I', then reverse 
 *     the segment of digits that corresponds to that sequence of 'D's.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the length of the input pattern. 
 *   Each character is processed once, and reversing a segment takes linear time.
 * - Space Complexity: O(n), for storing the initial string of digits.
 */
