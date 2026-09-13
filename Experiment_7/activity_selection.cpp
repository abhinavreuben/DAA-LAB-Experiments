#include <iostream>
#include <vector>
using namespace std;

struct Activity {
    int start;
    int finish;
};

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    vector<Activity> a(n);
    cout << "Enter start and finish time of each activity:\n";

    for (int i = 0; i < n; i++) 
        cin >> a[i].start >> a[i].finish;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].finish > a[j + 1].finish) {
                Activity temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "\nSelected activities:\n";
    int lastFinish = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].start >= lastFinish) {
            cout << "(" << a[i].start << ", "
                 << a[i].finish << ")" << endl;
            lastFinish = a[i].finish;
        }
    }
    return 0;
}
