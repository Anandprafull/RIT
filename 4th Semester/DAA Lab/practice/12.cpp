/* Fractional Knapsack

Pseudocode
function fracKnapsack(items, n, capacity):
    sort items in descending order of profit/weight ratio
    totalProfit = 0
    for i = 0 to n-1:
        if capacity >= items[i].weight:
            capacity -= items[i].weight
            totalProfit += items[i].profit
            print item fully included
        else:
            fraction = capacity / items[i].weight
            totalProfit += items[i].profit * fraction
            print item fractionally included
            break
    print totalProfit


    Complexity Analysis

Sorting: O(n log n) (for sorting items by profit/weight ratio)
Loop: O(n) (each item is considered at most once)
Total Time Complexity: O(n log n)
Space Complexity: O(1) (ignoring input storage; only a few variables used)
This is efficient and optimal for the fractional knapsack problemComplexity Analysis

*/

#include <bits/stdc++.h>

using namespace std;

struct item
{
    int weight;
    int profit;
};

bool cmp(item a, item b)
{
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

void fracKnapsack(item items[], int n, int capacity)
{
    double totalProfit = 0.0;
    sort(items, items + n, cmp);
    cout << "Selected items(profit,weight):" << endl;
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;

            cout << "(" << items[i].profit << "," << items[i].weight << ")- fully included" << endl;
        }
        else
        {
            double fraction = (double)capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            cout << "(" << items[i].profit << ", " << items[i].weight << ") - " << fraction * 100 << "% included" << endl;
            break;
        }
    }
    cout << "Maximum profit: " << totalProfit << endl;
}

int main()
{
    item items[] = {
        {1, 10}, {2, 15}, {3, 25}, {2, 12}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 5;

    clock_t start = clock();
    fracKnapsack(items, n, capacity);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken: " << time_taken << " ms" << endl;

    return 0;
}