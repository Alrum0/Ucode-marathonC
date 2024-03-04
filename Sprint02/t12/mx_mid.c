int mx_mid(int a, int b, int c) {
    int mid_of_three = a;
    if ((a <= b && b <= c) || (a >= b && b >= c)) {
        mid_of_three = b;
    }
    if ((a <= c && c <= b) || (a >= c && c >= b)) {
        mid_of_three = c;
    }
    return mid_of_three;
}




















