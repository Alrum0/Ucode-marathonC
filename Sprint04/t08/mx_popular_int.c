int mx_popular_int(const int* arr, int size) { 
    if (size <= 0) return 0; 
 
    int mostCommon = arr[0];   
    int maxCount = 1;         
 
    for (int i = 0; i < size; i++) { 
        int currentNumber = arr[i]; 
        int currentCount = 1; 
 
        for (int j = i + 1; j < size; j++) { 
            if (arr[j] == currentNumber) { 
                currentCount++; 
            } 
        } 
        if (currentCount > maxCount) {  
            mostCommon = currentNumber; 
            maxCount = currentCount; 
        } 
    } 
 
    return mostCommon; 
} 
 
