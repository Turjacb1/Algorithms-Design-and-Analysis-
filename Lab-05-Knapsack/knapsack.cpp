#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct Item {
    float value, weight, ratio;
};


bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}


int main() {
    int n;
    float capacity, total_value = 0;
    
    cin >> n;
    vector<Item> items(n);

    // Input value
    for(int i = 0; i < n; i++) {
        cin >> items[i].value;
    }

    
    for(int i = 0; i < n; i++) {
        cin >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    cin >> capacity;


    sort(items.begin(), items.end(), compare);

    for(int i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            // Take the whole item
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            // Take the fraction of the item
            total_value += items[i].ratio * capacity;
            break;
        }
    }

    cout << "Maximum value in knapsack = " << total_value << endl;

    return 0;
}
