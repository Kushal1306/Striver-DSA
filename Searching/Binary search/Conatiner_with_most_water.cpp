class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
    }
};
/*
int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        for(int i=0;i<height.size()-1;i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
              int area= min(height[i],height[j])*(j-i);
              maxi=max(maxi,area);
            }
        }
        return maxi;
    } 
*/