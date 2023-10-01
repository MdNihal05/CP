#include <iostream>
#include <vector>

using namespace std;

const int SZ = 1 << 17;
vector<int> andSum(2 * SZ);
vector<int> andLazy(2 * SZ);

void push(int i, int l, int r) {
    if (andLazy[i] != -1) {
        andSum[i] = andLazy[i];
        if (l < r) {
            andLazy[2 * i] = andLazy[i];
            andLazy[2 * i + 1] = andLazy[i];
        }
        andLazy[i] = -1;
    }
}

void pull(int i, int l, int r) {
    int m = (l + r) / 2;
    push(2 * i, l, m);
    push(2 * i + 1, m + 1, r);
    andSum[i] = andSum[2 * i] & andSum[2 * i + 1];
}

int query(int i, int l, int r, int a, int b) {
    push(i, l, r);
    if (r < a || b < l)
        return -1;  // Return a neutral value for AND operation.
    if (a <= l && r <= b) {
        return andSum[i];
    }
    int m = (l + r) / 2;
    int ql = query(2 * i, l, m, a, b);
    int qr = query(2 * i + 1, m + 1, r, a, b);
    if (ql == -1)
        return qr;
    if (qr == -1)
        return ql;
    return ql & qr;
}

void update(int i, int l, int r, int a, int b, int k) {
    push(i, l, r);
    if (r < a || b < l)
        return;
    if (a <= l && r <= b) {
        andLazy[i] = k;
        push(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(2 * i, l, m, a, b, k);
    update(2 * i + 1, m + 1, r, a, b, k);
    pull(i, l, r);
}

void printArray(int i, int l, int r) {
    push(i, l, r);
    if (l == r) {
        cout << andSum[i] << " ";
        return;
    }
    int m = (l + r) / 2;
    printArray(2 * i, l, m);
    printArray(2 * i + 1, m + 1, r);
}

int main() {
    // Example usage for bitwise AND:
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    // Build the segment tree from the vector
    for (int i = 0; i < n; i++) {
        update(1, 0, n - 1, i, i, arr[i]);
    }

    // Print the array represented by the segment tree
    cout << "Array represented by the segment tree: ";
    printArray(1, 0, n - 1);
    cout << endl;

    // Query the bitwise AND of elements in a range [l, r]
    int l = 1;
    int r = 3;
    int result = query(1, 0, n - 1, l, r);
    cout << "Bitwise AND of elements in range [" << l << ", " << r << "]: " << result << endl;

    // Update a range [l, r] with a value k
    int k = 2;
    update(1, 0, n - 1, l, r, k);

    // Query again after the update
    result = query(1, 0, n - 1, l, r);
    cout << "Bitwise AND of elements in range [" << l << ", " << r << "] after update: " << result << endl;

    return 0;
}
