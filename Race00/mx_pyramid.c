void mx_printchar(char c);

void mx_pyramid(int n) {
	if (n % 2 == 0 && n >= 1) {
		int side1 = 1;
		int side2 = 0;
		int side3 = (n * 2) - 3;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				for (int j = 0; j < ((side3 / 2) + 1); j++) {
					mx_printchar(' ');
				}
				mx_printchar('/');
				mx_printchar('\\');
				mx_printchar('\n');
			}
			else if (i < n / 2) {
				for (int j = ((side3 / 2) + 1 + 1 - i); j > 1; j--) {
					mx_printchar(' ');
				}
				mx_printchar('/');
				for (int j = 0; j < side1; j++) {
					mx_printchar(' ');
				}
				side1 +=2;
				mx_printchar('\\');
				for (int j = 0; j <= side2; j++) {
					mx_printchar(' ');
				}
				side2++;
				mx_printchar('\\');
				mx_printchar('\n');
			}
			else if (i >= n / 2 && i != n - 1) {
				for (int j = n - i; j > 1; j--) {
					mx_printchar(' ');
				}
				mx_printchar('/');
				for (int j = 0; j < side1; j++) {
					mx_printchar(' ');
				}
				side1 += 2;
				mx_printchar('\\');
				for (int j = side2 + 1; j > 1; j--) {
					mx_printchar(' ');
				}
				side2 --;
				mx_printchar('|');
				mx_printchar('\n');
			}
			else {
				mx_printchar('/');
				for (int j = 0; j < side3; j++) {
					mx_printchar('_');
				}
				mx_printchar('\\');
				mx_printchar('|');
				mx_printchar('\n');
			}
		}
	}
}

