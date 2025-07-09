#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int cost[4][4] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    vector<int> jobs = {0, 1, 2, 3};
    int min_cost = INT_MAX;
    vector<int> best_assignment;

    do {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += cost[i][jobs[i]];
        }

        if (total < min_cost) {
            min_cost = total;
            best_assignment = jobs;
        }
    } while (next_permutation(jobs.begin(), jobs.end()));

    cout << "Minimum Cost: " << min_cost << endl;
    cout << "Best Assignment:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Person " << i << " -> Job " << best_assignment[i] << endl;
    }

    return 0;
}
