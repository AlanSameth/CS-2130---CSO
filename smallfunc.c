#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

void capitalize(char *s){
        //iterate through string
        for(int count = 0; s[count] != '\0'; count++){

                //If equal to it in hex or between

                if(s[count] >= 'a' && s[count] <= 'z'){

                        //Subtract 2 in hex
                        s[count] -= 32;
                }
        }

        return;


}

void fibarray(unsigned char *dest, unsigned num){

        if (num == 0){
                return;
        }
        if(num >= 1){
                dest[0] = 1;
        }
        if(num >= 2){
                dest[1] = 1;
        }
       int count = 2;
        while(count < num){
                dest[count]= dest[count-1] + dest[count-2];
                count++;

        }

}

long recpow(long x, unsigned char e){
        if(e == '\0'){
                return 1;
        }
        if(e == '1'){
                return x;
        }
        return x * recpow(x, e - 1);


}

void reverse(int *arr, unsigned length){

    int *hold [length];
    int count = 0;
    for(int i = length -1; i >= 0; i--){
        
        hold[count] = arr[i];
        count++;
    }
    
    for(int j = 0; j < length; j++){
        
        arr[j] = hold[j];
    }
}

void push0(int *arr, unsigned length){

    int *hold[length];
    int count = 0;
    for(int i = 0; i < length; i++){
        if(arr[i] != 0){
            hold[count] = &arr[i];
            count++;
        }
    }
    
    for(int j = 0; j < count; j++){
        arr[j] = *hold[j];
    }
    
    
    while (count < length){
        arr[count] = 0;
        count++;
    }
    
}