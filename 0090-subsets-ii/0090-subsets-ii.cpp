class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int n, int idx, vector<int>& v){
        
        res.push_back(v);

        for(int i = idx; i<n; i++){
            if(i > idx && nums[i] == nums[i-1]) continue;

            v.push_back(nums[i]);
            dfs(nums, n, i+1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {    
        vector<int> v;
        sort(nums.begin(), nums.end());
        dfs(nums, nums.size(), 0, v);
        return res;
    }
};