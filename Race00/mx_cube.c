void mx_printchar(char c);

void mx_cube(int n) {
    if (n <= 1) return ;
  int edge1 = 1, edge2 = 1, edge3 = 1, h = 0;
  for (int i = 0; i < n + 3 + (n/2); i++) {
    for (int j = 0; j < n * 2 + 3 + (n/2); j++) {
      if ((j == 0 && (i == (n/2) + 1 || i == n + 2 + (n/2))) || (j == n * 2 + 1 && (i == (n/2) + 1 || i == n + (n/2) + 2)) || (i == 0 && ( j == (n/2) + 1 || j == n * 2 + 2 + (n/2))) || (j == n * 2 + 2 + (n/2) && i == n + 1)) mx_printchar ('+');
      else if (((j < n * 2 + 1 && (i == (n/2) + 1 || i == (n/2) + n + 2))) || (j > (n/2) + 1 && i == 0)) mx_printchar ('-');
      else if (((i > (n/2) + 1 && (j == 0 || j == n * 2 + 1))) || (i < n + 1 && j == n * 2 + 2 + (n/2)))  mx_printchar ('|');
      else if (i == edge1 && j == (n/2) + 1 - edge1 ) {
        mx_printchar ('/');
        edge1++;  
      }
      else if (i == edge2 && j == n * 2 + 2 + (n/2) - edge2) {
        mx_printchar ('/');
        edge2++;
      }
      else if (j == n * 2 + 2 + (n/2) - edge3 && i == n + 1 + edge3) {
        mx_printchar ('/');
        edge3++;
      }
      else if (j == n * 2 + 2 + (n/2) - h && i > n + 1 ){
        mx_printchar ('\n');
        h++;
      }
      else if (((j < n * 2 + 2 + (n/2) - h && i > n + 1)) || (i <= n + 1)) mx_printchar (' ');
    }
    if (i <= n + 1) mx_printchar ('\n');
    
  }
}

