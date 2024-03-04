#include <unistd.h> 
  
void mx_printint(int n); 
void mx_printchar(char c); 
 
void mx_print_arr_int(const int *arr, int size) { 
    if (arr == NULL || size <= 0) { 
        return;   
    } 
 
    for (int i = 0; i < size; i++) { 
        mx_printint(arr[i]);  
        mx_printchar('\n');   
    } 
} 
 
