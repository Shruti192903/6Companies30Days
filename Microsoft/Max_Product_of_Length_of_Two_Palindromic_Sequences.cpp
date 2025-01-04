// Maximum Product of the Length of Two Palindromic Subsequences

class Solution {
public:
    bool ispalindrome(string s1){
        string a=s1;;
        reverse(s1.begin(),s1.end());
      
        return a==s1;
    }
    unordered_map<string,int>maps;
    int find(string&s,int index,string s1,string s2){
        if(index==s.size()){
            if(s1.size() and s2.size() and ispalindrome(s1) and ispalindrome(s2)){
                return s1.size()*s2.size();
            }
            return 0;
        }
        string key=to_string(index)+","+s1+","+s2;
        if(maps.find(key)!=maps.end()){
            return maps[key];
        }
        int a=find(s,index+1,s1+s[index],s2);
        int b=find(s,index+1,s1,s2+s[index]);
        int c=find(s,index+1,s1,s2);
        return maps[key]=max(a,max(b,c));
    }
    int maxProduct(string&s) {
        
        return find(s,0,"","");
    }
};


/**
     * Definition:
     * The maxProduct function finds the maximum product of the lengths of two 
     * non-empty substrings of a given string `s`, such that both substrings are 
     * palindromes. A palindrome is a string that reads the same forwards and backwards.
     *
     * Approach:
     * 1. Use a recursive function `find` to explore all possible ways to split 
     *    the string into two substrings (`s1` and `s2`).
     * 2. For each character in the string, consider three options:
     *    - Add the character to `s1`.
     *    - Add the character to `s2`.
     *    - Skip the character.
     * 3. When reaching the end of the string, check if both `s1` and `s2` are 
     *    non-empty palindromes. If they are, calculate their product and return it.
     * 4. Use memoization (via an unordered map) to store results of previously 
     *    computed states to avoid redundant calculations.
     *
     * Time Complexity:
     * The time complexity is O(3^n) in the worst case due to three recursive calls 
     * made for each character in the string. However, memoization helps reduce 
     * redundant calculations significantly.
     *
     * Space Complexity:
     * The space complexity is O(n) for storing the recursion stack and O(n) for 
     * storing results in the unordered map.
**/
