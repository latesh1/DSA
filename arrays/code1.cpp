#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int sortarr(vector<int>&arr)
{
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
int main() {
    // Write C++ code here
    vector<int>arr1={2,3,1,6,7};
    vector<int>arr2={8,10,5,6,7};
    cout<<"largest no"<<sortarr(arr1)<<endl;
    cout<<"the largestno"<<sortarr(arr2);

    return 0;
}