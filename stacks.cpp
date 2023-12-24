for (int i = 0; i < n; i++) {
        cin >> v[i];
        while (stk.size() and v[i] > v[stk.top()]) {
            right[stk.top()] = i;
            stk.pop();
        }
        if (stk.size()) {
            left[i] = v[stk.top()];
        }
        stk.push(i);
}
