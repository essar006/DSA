class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& arr, int tar, vector<int>& v, int idx){

        if(tar == 0) {res.push_back(v); return;}
        if(idx == arr.size() || tar < 0) return;

        dfs(arr, tar, v, idx+1);

        v.push_back(arr[idx]);
        dfs(arr, tar-arr[idx], v, idx);
        v.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        dfs(candidates, target, v, 0); 

        return res;
    }
};