int low = 0, high = n;
while (high-low > 1) {
    int mid = low+(high-low) / 2;
    if (ok(mid))
        high = mid;
    else
        low = mid;
}

// low will be last false
// high will be first true
