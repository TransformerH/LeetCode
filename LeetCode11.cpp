//between the left line and the right line, only a line that higher than the shorter one of the both side lines may make a container with bigger size, since the wide must be shorter.
// same like quick sort
int maxArea(vector<int>& height) {
    int mV = 0;
    int left = 0;
    int right = (int)height.size() - 1;
    while(left < right){
        int shorter = min(height[left], height[right]);
        mV = max(mV, shorter * (right - left));
        while(height[left] <= shorter && left < right)
            left++;
        while(height[right] <= shorter && left < right)
            right--;
    }
   
    return mV;
}