class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int n, int idx){
        if(idx == n) res.push_back(nums);
        for(int i=idx; i<n; i++){
            swap(nums[i], nums[idx]);
            dfs(nums, n, idx+1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, nums.size(), 0);
        return res;
    }
};