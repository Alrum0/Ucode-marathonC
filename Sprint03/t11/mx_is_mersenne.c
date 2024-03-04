#include <stdbool.h>

double mx_pow(double n, unsigned int pow);
bool mx_is_prime(int num);

bool mx_is_mersenne(int n) {
  return (mx_is_prime(n) && !((n+1) &n));
}
