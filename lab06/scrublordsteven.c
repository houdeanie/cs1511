#include <stdio.h>

int main(void){
    int character = getchar();
    int alphabet[26]= {0};
    int i=0;
    int k = 'a';
    int counter;
    if ((character >= 'A' && character <='Z') || (character >='a' && character <= 'a')){
  
        
    counter = 0;
    while (character != EOF){
            while (k<='z'){
                if (character == k){
                    alphabet[i] = alphabet[i] +1; 
                counter++;               
                }
                i++;
                k++;
            }
        int j='A';
        int m=0;
            while (j<='Z'){
                if (character == i){
                    alphabet[m] = alphabet[m] +1;
                m++;
                counter++;
                }
            }
            character=getchar();
    }
    int l=0;
    double frequency[l];
    while (l < 26){
        frequency[l] = alphabet[l]/counter;
        l++;
    }
    int d=0;
    int letter = 'a';
    while (d < 26){
       printf("'%c' %lf %d \n", letter,frequency[d], alphabet[d]);//add frequency
       d++;
       letter++;
    }
    }
    return 0;
}
