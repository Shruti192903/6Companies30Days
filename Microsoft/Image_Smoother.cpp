// Image Smoother
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size() ; //row
        int n = img[0].size(); //column
        vector<vector<int>> result(m, vector<int>(n, 0));
       //Relative neighbour positions
        int x[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int y[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int sum = 0;
                int count = 0;
                for(int k=0; k<9; k++){ // Adding neighbor's value
                    int xi = i + x[k];
                    int yi = j + y[k];

                    if(xi >= 0 && xi < m && yi >= 0 && yi < n){
                        sum += img[xi][yi];
                        count++;
                    }
                }
                result[i][j] = sum/count ; // Floor division
            }
        }
        return result;
    }
};

/**
 * Definition:
 * The function `imageSmoother` takes a 2D vector representing an image
 * and applies a smoothing filter to it. Each pixel's new value is the average
 * of itself and its eight surrounding neighbors, rounded down to the nearest integer.
 *
 * Approach:
 * 1. Create an output matrix `result` of the same dimensions as the input image.
 * 2. For each pixel in the image, calculate the sum of itself and its valid neighbors.
 * 3. Count how many valid neighbors there are for each pixel.
 * 4. Store the average (floor division) in the corresponding position in `result`.
 *
 * Complexity:
 * - Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the image.
 * - Space Complexity: O(m * n) for storing the result.
 */
