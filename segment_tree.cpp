#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

template <typename T>
class SegmentTree {
private:
    struct Node {
        T sumVal;
        T maxVal;
        T minVal;
        T addVal;
        T gcdVal;
        T lcmVal;
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
            tree[v].gcdVal = arr[tl];
            tree[v].lcmVal = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            tree[v].sumVal = tree[v * 2].sumVal + tree[v * 2 + 1].sumVal;
            tree[v].maxVal = max(tree[v * 2].maxVal, tree[v * 2 + 1].maxVal);
            tree[v].minVal = min(tree[v * 2].minVal, tree[v * 2 + 1].minVal);
            tree[v].gcdVal = gcd(tree[v * 2].gcdVal, tree[v * 2 + 1].gcdVal);
            tree[v].lcmVal = lcm(tree[v * 2].lcmVal, tree[v * 2 + 1].lcmVal);
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
            return INT_MIN; // Neutral element for max
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
            return INT_MAX; // Neutral element for min
        }
        if (tl == l && tr == r) {
            return tree[v].minVal;
        }
        int tm = (tl + tr) / 2;
        T leftValue = queryMin(v * 2, tl, tm, l, min(r, tm));
        T rightValue = queryMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return min(leftValue, rightValue);
    }

    T queryGCD(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0; // Neutral element for GCD
        }
        if (tl == l && tr == r) {
            return tree[v].gcdVal;
        }
        int tm = (tl + tr) / 2;
        T leftValue = queryGCD(v * 2, tl, tm, l, min(r, tm));
        T rightValue = queryGCD(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return gcd(leftValue, rightValue);
    }

    T queryLCM(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 1; // Neutral element for LCM
        }
        if (tl == l && tr == r) {
            return tree[v].lcmVal;
        }
        int tm = (tl + tr) / 2;
        T leftValue = queryLCM(v * 2, tl, tm, l, min(r, tm));
        T rightValue = queryLCM(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return lcm(leftValue, rightValue);
    }

    void updateAdd(int v, int tl, int tr, int l, int r, T newVal) {
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[v].addVal += newVal;
            tree[v].sumVal += newVal * (tr - tl + 1);
            tree[v].maxVal += newVal;
            tree[v].minVal += newVal;
            tree[v].gcdVal += newVal;
            tree[v].lcmVal += newVal;
        } else {
            int tm = (tl + tr) / 2;
            updateAdd(v * 2, tl, tm, l, min(r, tm), newVal);
            updateAdd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, newVal);
            tree[v].sumVal = tree[v * 2].sumVal + tree[v * 2 + 1].sumVal;
            tree[v].maxVal = max(tree[v * 2].maxVal, tree[v * 2 + 1].maxVal);
            tree[v].minVal = min(tree[v * 2].minVal, tree[v * 2 + 1].minVal);
            tree[v].gcdVal = gcd(tree[v * 2].gcdVal, tree[v * 2 + 1].gcdVal);
            tree[v].lcmVal = lcm(tree[v * 2].lcmVal, tree[v * 2 + 1].lcmVal);
            tree[v].sumVal += tree[v].addVal * (tr - tl + 1);
            tree[v].maxVal += tree[v].addVal;
            tree[v].minVal += tree[v].addVal;
            tree[v].gcdVal += tree[v].addVal;
            tree[v].lcmVal += tree[v].addVal;
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

    T rangeGCDQuery(int l, int r) {
        return queryGCD(1, 0, n - 1, l, r);
    }

    T rangeLCMQuery(int l, int r) {
        return queryLCM(1, 0, n - 1, l, r);
    }

    void rangeAdd(int l, int r, T newVal) {
        updateAdd(1, 0, n - 1, l, r, newVal);
    }
};

int main() {
    vector<int> arr = {12, 18, 24, 36, 48};

// Create an instance of the SegmentTree for addition, maximum, minimum, GCD, and LCM (integer type)
    SegmentTree<int> multiOpSegmentTree(arr);

// Example usage of various queries and updates
    cout << "Sum in range [1, 3]: " << multiOpSegmentTree.rangeSumQuery(1, 3) << endl;
    cout << "Max in range [0, 4]: " << multiOpSegmentTree.rangeMaxQuery(0, 4) << endl;
    cout << "Min in range [2, 4]: " << multiOpSegmentTree.rangeMinQuery(2, 4) << endl;
    cout << "GCD in range [0, 2]: " << multiOpSegmentTree.rangeGCDQuery(0, 2) << endl;
    cout << "LCM in range [1, 4]: " << multiOpSegmentTree.rangeLCMQuery(1, 4) << endl;

// Add 5 to the range [1, 3]
    multiOpSegmentTree.rangeAdd(1, 3, 5);

// Query again after updates
    cout << "Sum in range [1, 3]: " << multiOpSegmentTree.rangeSumQuery(1, 3) << endl;
    cout << "Max in range [0, 4]: " << multiOpSegmentTree.rangeMaxQuery(0, 4) << endl;
    cout << "Min in range [2, 4]: " << multiOpSegmentTree.rangeMinQuery(2, 4)
         << endl;
    cout << "GCD in range [0, 2]: " << multiOpSegmentTree.rangeGCDQuery(0, 2) << endl;
    cout << "LCM in range [1, 4]: " << multiOpSegmentTree.rangeLCMQuery(1, 4) << endl;

    return 0;
}
