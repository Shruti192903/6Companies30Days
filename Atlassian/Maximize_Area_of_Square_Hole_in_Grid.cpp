//Maximize Area of Square Hole in Grid

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& num1, vector<int>& num2) {
          
            sort(num1.begin(),num1.end());
            sort(num2.begin(),num2.end());
              
               int ver_count=1;
               int max_vcount=1;
                for(int i=0;i<num1.size()-1;i++){
                        if(num1[i]+1==num1[i+1]) ver_count++;
                         else {
                            ver_count=1;
                         }
                            max_vcount= max(max_vcount,ver_count);
                         
                  }
                     
               int hor_count=1;
               int max_hcount=1;   
                      for(int i=0;i<num2.size()-1;i++){
                        if(num2[i]+1==num2[i+1]) hor_count++;
                         else {
                            hor_count=1;
                         }
                            max_hcount=max(max_hcount,hor_count);
                         
                  }
                      int ans=min(max_vcount,max_hcount)+1;
                      return ans*ans;
    }
};

/*
 * Definition:
 * The problem involves finding the maximum area of a square hole that can be formed 
 * based on given vertical and horizontal positions. The positions are represented 
 * by two vectors containing integer values.
 *
 * Approach:
 * - Sort both vectors to facilitate finding consecutive numbers.
 * - Count the maximum number of consecutive vertical and horizontal positions.
 * - The side length of the largest square hole is determined by the smaller 
 *   of these two counts plus one (to include the starting position).
 *
 * Complexity:
 * - Time Complexity: O(n log n + m log m), where n is the size of num1 and m is 
 *   the size of num2 due to sorting operations.
 * - Space Complexity: O(1), as we use a constant amount of extra space for counters.
 */
