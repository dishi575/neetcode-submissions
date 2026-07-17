class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        stack<pair<int,int>> st;
        for(int i=0;i<heights.size();i++){
            int start=i;
            while(!st.empty() && st.top().second>heights[i]){
                pair<int,int> top=st.top();
                st.pop();
                int ind=top.first;
                int height=top.second;
                area=max(area,height*(i-ind));
                start=ind;
            }
            st.push({start,heights[i]});
        }
        while(!st.empty()){
            int ind=st.top().first;
            int height=st.top().second;
            area=max(area, (int)(height*(heights.size()-ind)));
            st.pop();
        }
        return area;
    }
};
