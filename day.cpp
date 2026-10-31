#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> largestelement(vector<int>& a){
    vector<int> result(a.size(),0);
    stack<int> st;
    
    for(int i=0; i<a.size();++i){
        
        while(!st.empty() && a[st.top()] <= a[i]){
            int previndex = st.top();
            st.pop();
            result[previndex] = i - previndex;
        }
        
        st.push(i);
    }
    
    return result;
}

int main()
{

    vector<int> array = {73, 74, 75, 71, 69, 72, 76, 73};
    for(int x :largestelement(array))
        cout << x << " ";
    return 0;
}
