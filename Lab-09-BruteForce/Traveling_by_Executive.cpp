#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    const int N = 4;

    
    int graph[N][N] = {
        {0, 2, 8, 5},  
        {2, 0, 3, 4},  
        {8, 3, 0, 7},  
        {5, 4, 7, 0}   };

    vector<int> cities = {1, 2, 3}; 
    int mincost = INT_MAX;
    vector<int> bestpath;

    do {
        int currentcost = 0;
        int currentcity = 0; 

       
        for (int i = 0; i <cities.size(); i++) {
            currentcost += graph[currentcity][cities[i]];
            currentcity = cities[i];
        }
        currentcost += graph[currentcity][0]; 

        if (currentcost < mincost) {
            mincost = currentcost;
            bestpath = cities;
        }

    } while (next_permutation(cities.begin(), cities.end()));

    
    cout << "Minimum TSP Cost: "<< mincost << endl;
    cout << "Path: a -> ";
    for (int city : bestpath) {
        cout << char('a'+ city) <<"->";
    }
    cout<<"a"<< endl;

    return 0;
}
