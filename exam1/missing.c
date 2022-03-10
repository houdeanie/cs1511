#include <stdio.h>
#include <assert.h>

int missingNumber(int *array, int size){
    int loop = 0;
    int loop1 = 0;
    int loop2 = 0;
    int num = 1;
    int norm[size + 1];
    int check;
    while (loop < size + 1) {
        norm[loop] = num;
        loop++;
        num++;
    }
    loop = 0;
    while (loop1 < size + 1) {
        check = 0;
        while (loop2 < size) {
            if (norm[loop1] == array[loop2]) {
                loop1++;
                loop2 = 0;
                check = 1;
            }
            loop2++;
        }
        if(check != 1) {
            return norm[loop1];
        }
    }
    return 0;
}

// Don't touch these!
int main(){
	int a1[] = {1,2,3,4,5,7,8,9,10,11};
	int a2[] = {11,10,9,1,3,2,4,5,6,8};

	assert(missingNumber(a1,10) == 6);
	assert(missingNumber(a2,10) == 7);

	printf("Congrats you passed!\n");

	return 0;
}

