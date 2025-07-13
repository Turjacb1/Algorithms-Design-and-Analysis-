#include <iostream>
#include <vector>
using namespace std;


void knapsack(int index, int currentweight, int currentvalue,
              int capacity, const vector<int>& weights, const vector<int>& values,
              int& maxvalue) {
    
    if (index == weights.size()) {
        if (currentweight <= capacity) {
            maxvalue = max(maxvalue, currentvalue);
        }
        
        
        
        return;
    }

   
    knapsack(index + 1, currentweight + weights[index], currentvalue + values[index],
             capacity, weights, values, maxvalue);

    
    knapsack(index + 1, currentweight, currentvalue,
             capacity, weights, values, maxvalue);
}

int main() {
   
    vector<int> weights = {2, 5, 10, 5};
    vector<int> values  = {20, 30, 50, 10};
    int capacity = 16;

    int maxvalue = 0;

    knapsack(0, 0, 0, capacity, weights, values, maxvalue);

    cout << "Maximum value in knapsack: " << maxvalue << endl;

    return 0;
}
