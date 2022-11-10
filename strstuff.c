#include <stdio.h>
#include <string.h>
#include <stdlib.h>
size_t strlen(const char* s)
char *simple_split(char* s, char delim)

int main() {
        char *trash, *bit, *s;
trash = bit = s = strdup("can all aardvarks quaff?");
do {
    s = bit;
    bit = simple_split(s, 'a');
    puts(s);
} while(bit);
free(trash);
        return 0;
}
size_t strlen(const char* s) {
        int count = 0;
        char *s2 = strdup(s);
        while(s2[count]!= '\0'){
                count++;
        }
        free(s2);
        return count;
}

char *simple_split(char* s, char delim) {
        char *s2 = strdup(s);
        if(s2 == NULL || strlen(s2) == 0){
                return NULL;
        }
        int count = 0;
        while(s2[count] != delim && s[count] != '\0'){
                count++;
        }

        s2[count] = '\0';

        char *s3 = s2[count+1];
        return s3
}
