class Solution {
    public int maxArea(int[] height) {
       // represents the x axis 
        int x = 0;
        // represents the y axis 
        int y = 0;
        int area = 0;
        int result = 0;
        for (int i = 0; i < height.length; i++) {
            for (int j = 1; j < height.length; j++) {
                x = j-i; // gives length of x axis
                y = Math.min(height[i], height[j]);
                area = x * y;
                if (area > result) {
                    result = area;
                }
                            }
        }
        return result;
            }
}