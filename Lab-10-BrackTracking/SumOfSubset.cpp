#include <iostream>
#include <vector>
using namespace std;




void subsetsum(vector<int>& arr,int index,int target,vector<int>& subset, int currentSum) {
    if (currentSum==target) {
        cout << "{";
        for (int num:subset)
            cout << num << " ";
        cout << "}"<<endl;
        return;
    }

    if (index ==arr.size()||currentSum >target)
        return;

  
    subset.push_back(arr[index]);


    subsetsum(arr,index + 1,target,subset,currentSum +arr[index]);

    
    subset.pop_back();
    subsetsum(arr,index + 1,target,subset,currentSum);}



 int main() {
    vector<int> arr = {2,1,4,3};  
    int target = 5;                               

    vector<int> subset;
    cout << "Subsets with sum " <<target << ":\n";
    subsetsum(arr,0,target,subset,0);

    return 0;
}
