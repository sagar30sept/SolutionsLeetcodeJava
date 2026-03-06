class Solution {
    public int trap(int[] height) {
        if (height == null || height.length == 0) return 0;
        int l = 0, r = height.length - 1, leftMax = Integer.MIN_VALUE, rightMax = Integer.MIN_VALUE, ans = 0;
        while (l < r) {
            leftMax = Math.max(leftMax, height[l]);
            rightMax = Math.max(rightMax, height[r]);
            ans += (leftMax < rightMax) ? leftMax - height[l++] : rightMax - height[r--];
        }
        return ans;
    }
}
