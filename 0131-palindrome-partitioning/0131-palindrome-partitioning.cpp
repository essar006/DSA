class Solution {
public:
    vector<vector<string>> res;
    vector<string> v;
    bool isPalindrome(string &pal){
        int n = pal.size();
        for(int i=0; i<n/2; i++){
            if(pal[i] != pal[n-1-i])
                return false;
        }
        return true;
    }

    void solve(const string &s, int start){
        //base condition
        if(start == s.size()){
            res.push_back(v);
            return;
        }
        
        for(int i = start; i<s.size(); i++){
            string substrr = s.substr(start, i-start+1);
            if(isPalindrome(substrr)){
                v.push_back(substrr);
                solve(s, i+1);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return res;
    }
};