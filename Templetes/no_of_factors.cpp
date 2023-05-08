int count_factors(ll a) {
    int num = 1, fact = 0;
    while (num * num <= a) {
        if (a % num == 0) {
            fact++;

            if (a / num != num) {
                fact++;
            }
        }
        num++;
    }
    return fact;
}
