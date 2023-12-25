vector<int>left(n, -1), right(n, -1);
stack<int>stk;
for (int i = 0; i < n; i++) {
        while (stk.size() and v[i] > v[stk.top()]) {
            right[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
}
while (stk.size())stk.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (stk.size() and v[i] > v[stk.top()]) {
            left[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
}
debug(left, right);
