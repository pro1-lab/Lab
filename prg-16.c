
	#include <stdio.h>
#include <string.h>

int main() {
   
    char S1[] = "Flowers";
    char S2[] = "are beautiful";
    char result[100];  
    char *substr; 
	char *pos;

 
    int length_S1 = strlen(S1);
    printf("Length of S1: %d\n", length_S1);

    
    strcpy(result, S1); 
    strcat(result, " "); 
    strcat(result, S2);  
    printf("Concatenated string (S1 + S2): %s\n", result);

 
    substr = strstr(S1, "low");  
    if (substr) {
	printf("Extracted substring: %.*s\n", 3, substr); // Print first 3 characters of found substring
    } else {
	printf("Substring 'low' not found in S1.\n");
    }

   
     pos = strstr(S2, "are");  
    if (pos) {
	strncpy(pos, "is", 2);  
	strcpy(pos + 2, pos + 4); 
	printf("Modified string S2: %s\n", S2);
    } else {
        printf("\"are\" not found in S2.\n");
    }

    return 0;
}