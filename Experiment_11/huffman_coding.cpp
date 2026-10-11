#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    int left, right;
};

void printCodes(vector<Node>& tree, int root, string code) {
    if (root == -1)
        return;
    if (tree[root].left == -1 && tree[root].right == -1) {
        cout << tree[root].ch << " : " << code << endl;
        return;
    }
    printCodes(tree, tree[root].left, code + "0");
    printCodes(tree, tree[root].right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    vector<Node> tree;
    vector<bool> used;
    cout << "Enter characters and frequencies:\n";
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;

        tree.push_back({ch, freq, -1, -1});
        used.push_back(false);
    }

    while (true) {
        int min1 = -1, min2 = -1;
        for (int i = 0; i < tree.size(); i++) {
            if (used[i])
                continue;
            if (min1 == -1 || tree[i].freq < tree[min1].freq) {
                min2 = min1;
                min1 = i;
            }
            else if (min2 == -1 || tree[i].freq < tree[min2].freq)
                min2 = i;
        }

        if (min2 == -1)
            break;
        int sum = tree[min1].freq + tree[min2].freq;
        tree.push_back({'$', sum, min1, min2});
        used.push_back(false);
        used[min1] = true;
        used[min2] = true;
    }
    cout << "\nHuffman Codes:\n";
    printCodes(tree, tree.size() - 1, "");
    return 0;
}

