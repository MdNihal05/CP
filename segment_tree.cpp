#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
private:
    struct Node {
        T sumVal;
        T maxVal;
        T minVal;
        T addVal;
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

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v].sumVal = arr[tl];
            tree[v].maxVal = arr[tl];
            tree[v].minVal = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            tree[v].sumVal = tree[v * 2].sumVal + tree[v * 2 + 1].sumVal;
            tree[v].maxVal = max(tree[v * 2].maxVal, tree[v * 2 + 1].maxVal);
            tree[v].minVal = min(tree[v * 2].minVal, tree[v * 2 + 1].minVal);
        }
    }

    T querySum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0; // Neutral element for sum
        }
        if (tl == l && tr == r) {
            return tree[v].sumVal;
        }
        int tm = (tl + tr) / 2;
        T leftValue = querySum(v * 2, tl, tm, l, min(r, tm));
        T rightValue = querySum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return leftValue + rightValue;
    }

    T queryMax(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return numeric_limits<T>::min(); // Neutral element for max
        }
        if (tl == l && tr == r) {
            return tree[v].maxVal;
        }
        int tm = (tl + tr) / 2;
        T leftValue = queryMax(v * 2, tl, tm, l, min(r, tm));
        T rightValue = queryMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return max(leftValue, rightValue);
    }

    T queryMin(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return numeric_limits<T>::max(); // Neutral element for min
        }
        if (tl == l && tr == r) {
            return tree[v].minVal;
        }
        int tm = (tl + tr) / 2;
        T leftValue = queryMin(v * 2, tl, tm, l, min(r, tm));
        T rightValue = queryMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return min(leftValue, rightValue);
    }

    void updateAdd(int v, int tl, int tr, int l, int r, T newVal) {
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[v].addVal += newVal;
            tree[v].sumVal += newVal * (tr - tl + 1);
            tree[v].maxVal += newVal;
            tree[v].minVal += newVal;
        } else {
            int tm = (tl + tr) / 2;
            updateAdd(v * 2, tl, tm, l, min(r, tm), newVal);
            updateAdd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, newVal);
            tree[v].sumVal = tree[v * 2].sumVal + tree[v * 2 + 1].sumVal;
            tree[v].maxVal = max(tree[v * 2].maxVal, tree[v * 2 + 1].maxVal);
            tree[v].minVal = min(tree[v * 2].minVal, tree[v * 2 + 1].minVal);
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
};

int main() {
    vector<int> arr = {12, 18, 24, 36, 48};

    // Create an instance of the SegmentTree for addition, maximum, and minimum (integer type)
    SegmentTree<int> multiOpSegmentTree(arr);

    // Example usage of various queries and updates
    cout << "Sum in range [1, 3]: " << multiOpSegmentTree.rangeSumQuery(1, 3) << endl;
    cout << "Max in range [0, 4]: " << multiOpSegmentTree.rangeMaxQuery(0, 4) << endl;
    cout << "Min in range [2, 4]: " << multiOpSegmentTree.rangeMinQuery(2, 4) << endl;

    // Add 5 to the range [1, 3]
    multiOpSegmentTree.rangeAdd(1, 3, 5);

    // Query again after updates
    cout << "Sum in range [1, 3]: " << multiOpSegmentTree.rangeSumQuery(1, 3) << endl;
    cout << "Max in range [0, 4]: " << multiOpSegmentTree.rangeMaxQuery(0, 4) << endl;
    cout << "Min in range [2, 4]: " << multiOpSegmentTree.rangeMinQuery(2, 4) << endl;

    return 0;
}
