class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;  // maps each num2 element → its NGE
        stack<int> st; // monotonic decreasing stack

        // Process nums2 from left to right
        for (int num : nums2) {
            // If current number is greater, it's the NGE for st.top()
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // For elements still in stack → no next greater exists
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Build answer for nums1
        vector<int> result;
        for (int x : nums1) {
            result.push_back(nextGreater[x]);
        }

        return result;
    }
};
