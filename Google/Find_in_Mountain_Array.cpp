// Find in Mountain Array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low1=1;
        int hi=mountainArr.length()-2;
        while(low1!=hi){
            int idx=(low1+hi)/2;
            if(mountainArr.get(idx)<mountainArr.get(idx+1)){
                low1=idx+1;
            }else{
                hi=idx;
            }
        }
        int peek=low1;
        int low=0,high=peek;
        // if(mountainArr.get(peek)>=target){
            while(low!=high){   
                int mid=(low+high)/2;
                if(mountainArr.get(mid)<target){
                    low=mid+1;
                }else{
                    high=mid;
                }
            }
            if(mountainArr.get(low)==target){
                return low;
            }
            low=peek+1;
            high=mountainArr.length()-1;
            while(low!=high){
                int midr=(low+high)/2;
                if(mountainArr.get(midr)>target){
                    low=midr+1;
                }else{
                    high=midr;
                }
            }
            if(mountainArr.get(low)==target){
                return low;
            }
        return -1;
    }
};


/*
 * Definition:
 * The problem involves searching for a target value in a mountain array,
 * which is an array that first increases and then decreases. The goal 
 * is to find the index of the target using efficient search methods.
 *
 * Approach:
 * - First, find the peak of the mountain using binary search.
 * - Then, perform binary search in both the increasing and decreasing 
 *   parts of the array to locate the target value.
 *
 * Complexity:
 * - Time Complexity: O(log N), where N is the number of elements in 
 *   the mountain array. Both finding the peak and searching for 
 *   the target are done using binary search.
 * - Space Complexity: O(1), as we are using a constant amount of space 
 *   for variables.
 */
