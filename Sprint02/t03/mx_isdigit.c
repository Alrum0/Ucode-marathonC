#include <stdbool.h>

bool mx_isdigit(int c) {
	if(c >= '0' && c <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}

