// find the maximum profit 
// m = capacity of knapsack(or bag)
// n = number of objects
// P = array of profits
// W = array of weights

#include<bits/stdc++.h>
using namespace std;

struct Item {
    int profit ; // profit value
    int weight ; // weight value
};

bool compare(Item a, Item b) // comparing two items profit/weight ratio
{
    double p1 = (double)a.profit/a.weight ;
    double p2 = (double)b.profit/b.weight ;

    return p1 > p2 ; // sort items in descending order
}

double fractionalKnapsack(int m, int n, int p[], int w[])
{
    vector<Item> item(n) ; // ek vector hai jisme two values store hogi of each item, its profit and weight
    for(int i=0; i<n; i++)
    {
        item.push_back({p[i], w[i]}) ;
    }

    sort(item.begin(), item.end(), compare) ; // ab items ko sort krna hai according to decreasing order of profit/weight ratio

    double totalProfit = 0.0 ;
    int rem = m ;

    for(auto& items : item)
    {
        if(rem >= items.weight) // If the item can be taken completely
        {
            rem -= items.weight ;
            totalProfit += items.profit ;
        }
        else // Take fraction of the item
        {
            totalProfit += items.profit * ((double)rem/items.weight) ;
            break ; // Knapsack is full
        }
    }
    return totalProfit;
}

int main() {
    int n, m;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> m;

    int p[n], w[n];
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i];
    }

    double maxProfit = fractionalKnapsack(m, n, p, w);
    cout << "Maximum profit: " << maxProfit << endl;
    
    return 0;
}














