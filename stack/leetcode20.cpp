#include<bits/stdc++.h>
using namespace std;
class Solution{
    public :
    bool isvalid(string s){
        stack<char>st;
        for(auto it:s ){
            if(it =='('||it =='{'|| it =='[')
            st.push(it);
            else{
                if(st.empty())return false;
                char ch = st.top();
                st.pop();
                if
                (
                    (it ==')'&& ch =='(')
                   || (it ==']'&& ch =='[')
                   || (it =='}'&& ch =='{')
                )
                continue;
                else 
                return false;
            }
        }
        return st.empty();
    }
};
int main() {
    Solution sol;
    string s = "()[{}()]";

    if (sol.isvalid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}