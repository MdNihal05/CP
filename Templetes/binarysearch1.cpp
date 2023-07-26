int low = 0, high = n, ans = n;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (ok(mid)) {
    high = mid - 1;
    ans = mid;
    } else low = mid + 1;
}
