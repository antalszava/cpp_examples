int maxArea(vector<int>& height) {
  int max_area = 0;
  int l = 0;
  int r = height.size() - 1;
        
  while (l < r){
    int temp_area = std::min(height[l],height[r])*(r-l);
    max_area = (temp_area > max_area) ? temp_area : max_area;
    if (height[l] < height[r])
      l++;
    else
      r--;
  }
  return max_area;
}
    
