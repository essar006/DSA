class Solution {
public:
vector<vector<int>> res;
    void dfs(vector<int>& nums, int idx){
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            dfs(nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};