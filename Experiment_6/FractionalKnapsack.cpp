/*
Roll No: 25/DA/002
Name: Abhinav Reuben Topno
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (int i = 0; i < items.size(); i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else {
            totalValue += (double)items[i].value / items[i].weight * capacity;
            capacity = 0;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;
    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value = " << maxValue << endl;
    return 0;
}

