#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int SZ = 1 << 17;

template <typename T>
class SegmentTree {
private:
    struct Node {
        T sumVal;
        T maxVal;
        T minVal;
        T addVal;
        T xorVal;
    };

    vector<Node> tree;
    vector<T> arr;
    int n;

    T gcd(T a, T b) {
        while (b != 0) {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    T lcm(T a, T b) {
        return (a / gcd(a, b)) * b;
    }

    void push(int i, int l, int r) {
        if (tree[i].addVal != 0) {
            tree[i].sumVal += (r - l + 1) * tree[i].addVal;
            tree[i].maxVal += tree[i].addVal;
            tree[i].minVal += tree[i].addVal;
            if (l < r) {
                tree[2 * i].addVal += tree[i].addVal;
                tree[2 * i + 1].addVal += tree[i].addVal;
            }
            tree[i].addVal = 0;
        }
        if (tree[i].xorVal != 0) {
            tree[i].sumVal ^= (r - l + 1) * tree[i].xorVal;
            tree[i].maxVal ^= tree[i].xorVal;
            tree[i].minVal ^= tree[i].xorVal;
            if (l < r) {
                tree[2 * i].xorVal ^= tree[i].xorVal;
                tree[2 * i + 1].xorVal ^= tree[i].xorVal;
            }
            tree[i].xorVal = 0;
        }
    }

    void pull(int i, int l, int r) {
        int m = (l + r) / 2;
        push(2 * i, l, m);
        push(2 * i + 1, m + 1, r);
        tree[i].sumVal = tree[2 * i].sumVal + tree[2 * i + 1].sumVal;
        tree[i].maxVal = max(tree[2 * i].maxVal, tree[2 * i + 1].maxVal);
        tree[i].minVal = min(tree[2 * i].minVal, tree[2 * i + 1].minVal);
    }

    void build(int i, int l, int r) {
        if (l == r) {
            tree[i].sumVal = arr[l];
            tree[i].maxVal = arr[l];
            tree[i].minVal = arr[l];
            tree[i].addVal = 0;
            tree[i].xorVal = 0;
        } else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            pull(i, l, r);
        }
    }

public:
    SegmentTree(vector<T>& inputArray) {
        n = inputArray.size();
        arr = inputArray;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    T rangeSumQuery(int l, int r) {
        return querySum(1, 0, n - 1, l, r);
    }

    T rangeMaxQuery(int l, int r) {
        return queryMax(1, 0, n - 1, l, r);
    }

    T rangeMinQuery(int l, int r) {
        return queryMin(1, 0, n - 1, l, r);
    }

    void rangeAdd(int l, int r, T newVal) {
        updateAdd(1, 0, n - 1, l, r, newVal);
    }

    void rangeXOR(int l, int r, T newVal) {
        updateXOR(1, 0, n - 1, l, r, newVal);
    }

    void updateAdd(int i, int l, int r, int ql, int qr, T newVal) {
        push(i, l, r);
        if (qr < l || ql > r) return;
        if (ql <= l && qr >= r) {
            tree[i].addVal += newVal;
            push(i, l, r);
        } else {
            int m = (l + r) / 2;
            updateAdd(2 * i, l, m, ql, qr, newVal);
            updateAdd(2 * i + 1, m + 1, r, ql, qr, newVal);
            pull(i, l, r);
        }
    }

    void updateXOR(int i, int l, int r, int ql, int qr, T newVal) {
        push(i, l, r);
        if (qr < l || ql > r) return;
        if (ql <= l && qr >= r) {
            tree[i].xorVal ^= newVal;
            push(i, l, r);
        } else {
            int m = (l + r) / 2;
            updateXOR(2 * i, l, m, ql, qr, newVal);
            updateXOR(2 * i + 1, m + 1, r, ql, qr, newVal);
            pull(i, l, r);
        }
    }

    T querySum(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (qr < l || ql > r) return 0;
        if (ql <= l && qr >= r) return tree[i].sumVal;
        int m = (l + r) / 2;
        T leftValue = querySum(2 * i, l, m, ql, qr);
        T rightValue = querySum(2 * i + 1, m + 1, r, ql, qr);
        return leftValue + rightValue;
    }

    T queryMax(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (qr < l || ql > r) return numeric_limits<T>::min();
        if (ql <= l && qr >= r) return tree[i].maxVal;
        int m = (l + r) / 2;
        T leftValue = queryMax(2 * i, l, m, ql, qr);
        T rightValue = queryMax(2 * i + 1, m + 1, r, ql, qr);
        return max(leftValue, rightValue);
    }

    T queryMin(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (qr < l || ql > r) return numeric_limits<T>::max();
        if (ql <= l && qr >= r) return tree[i].minVal;
        int m = (l + r) / 2;
        T leftValue = queryMin(2 * i, l, m, ql, qr);
        T rightValue = queryMin(2 * i + 1, m + 1, r, ql, qr);
        return min(leftValue, rightValue);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    // Create an instance of the SegmentTree for addition, maximum, minimum, and XOR (integer type)
    SegmentTree<int> multiOpSegmentTree(arr);

    // Example usage of various queries and updates
    cout << "Sum in range [1, 3]: " << multiOpSegmentTree.rangeSumQuery(1, 3) << endl;
    cout << "Max in range [0, 4]: " << multiOpSegmentTree.rangeMaxQuery(0, 4) << endl;
    cout << "Min in range [2, 4]: " << multiOpSegmentTree.rangeMinQuery(2, 4) << endl;

    // Add 5 to the range [1, 3]
    multiOpSegmentTree.rangeAdd(1, 3, 5);

    // XOR 3 to the range [2, 4]
    multiOpSegmentTree.rangeXOR(2, 4, 3);

    // Query again after updates
    cout << "Sum in range [1, 3]: " << multiOpSegmentTree.rangeSumQuery(1, 3) << endl;
    cout << "Max in range [0, 4]: " << multiOpSegmentTree.rangeMaxQuery(0, 4) << endl;
    cout << "Min in range [2, 4]: " << multiOpSegmentTree.rangeMinQuery(2, 4) << endl;

    return 0;
}
