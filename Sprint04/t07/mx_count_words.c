int mx_count_words(const char* str, char delimiter) { 
    int count = 0; 
    int inWord = 0;  
 
    while (*str != '\0') { 
        if (*str != delimiter) { 
             if (!inWord) { 
                count++; 
                inWord = 1;   
            } 
        } else {  
            inWord = 0; 
        } 
 
        str++;   
    } 
 
    return count; 
} 
 
