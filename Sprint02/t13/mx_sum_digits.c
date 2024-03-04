int mx_sum_digits(int num) {
    int sum_of_digits = 0;
    if (num < 0) {
        num *= -1;
    }
    while (num > 0) {
        sum_of_digits += num % 10;
        num /= 10;
    }
    return sum_of_digits;
}



















