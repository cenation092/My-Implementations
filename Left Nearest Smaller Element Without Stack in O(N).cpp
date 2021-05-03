vector<int> Solution::leftNearestSmaller(vector<int> &A) {
    vector<int> ans;
    for( int i = 0; i < A.size(); i++ ){
        int idx = i-1;
        while(idx != -1){
            if( A[idx] < A[i] )break;
            idx = ans[idx];
        }
        ans.push_back(idx);
    }
    for( int i = 0; i < A.size(); i++ ){
        if( ans[i] != -1 )ans[i] = A[ans[i]];
    }
    return ans;
}
