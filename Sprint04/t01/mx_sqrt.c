int mx_sqrt(int x) { 
    if (x < 0) { 
        return 0; 
    } 
    if (x == 0 || x == 1) { 
        return x;  
    } 
 
    int start = 1, end = x, result = 0; 
    while (start <= end) { 
        int mid = start + (end - start) / 2; 
 
        if (mid * mid == x) { 
            return mid;  
        } 
 
        if (mid * mid < x) { 
            start = mid + 1; 
            result = mid; 
        } else { 
            end = mid - 1; 
        } 
    } 
 
    return result * result == x ? result : 0; 
} 
 

