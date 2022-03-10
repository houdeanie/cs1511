// Practice question for my cs1511 class
// I won't release solutions, you have to come to my thu13-sitar or fri09-sitar class
/*
  Write a function that determines the order of an array. Return ASCENDING if ascending, DESCENDING if DESCENDING,
  or UNDETERMINED if neither. Adjacent duplicates are considered both ascending and descending.
*/

#include <stdio.h>
#include <assert.h>

#define ASCENDING 1
#define DESCENDING 2
#define UNDETERMINED 3

/*
  EDIT THIS FUNCTION ONLY
*/
int determineOrder(int * array, int size) {
    int loop = 0;
    int up = 0;
    int down = 0;
    int equals = 0;
	
	if (size <= 1) {
    	return UNDETERMINED;
    }
    
    while (loop < size - 1) {
        if (array[loop] < array[loop + 1]) {
            up++;
        } else if (array[loop] > array[loop + 1]){
            down++;
        } else {
        	equals++;
        }
        loop++;
    }
    if (equals > 0 && up > 0) {
        return ASCENDING;
    }
    if (up == size - 1 && up > 0) {
        return ASCENDING;
    }
    if (equals > 0 && down > 0){
        return DESCENDING;
    }
    if (down == size - 1 && down > 0){
        return DESCENDING;
    }
    if (equals == size - 1) {
        return UNDETERMINED;
    }
    if (up > 0 && down > 0 && down != size - 1 && up != size - 1) {
        return UNDETERMINED;
    }
    return 0;
}

int main(){
  int a1[] = {1,2,3,4,5};
  int a2[] = {1,5};
  int a3[] = {1,2,432,524,999};
  int d1[] = {65,32,1};
  int d2[] = {9,8,7,6};
  int d3[] = {3,3,3,2};
  int u1[] = {1,2,3,4,5,4};
  int u2[] = {1,1,1,1};
  int u3[] = {1};

  assert(determineOrder(a1, sizeof(a1)/sizeof(int)) == ASCENDING);
  assert(determineOrder(a2, sizeof(a2)/sizeof(int)) == ASCENDING);
  assert(determineOrder(a3, sizeof(a3)/sizeof(int)) == ASCENDING);

  assert(determineOrder(d1, sizeof(d1)/sizeof(int)) == DESCENDING);
  assert(determineOrder(d2, sizeof(d2)/sizeof(int)) == DESCENDING);
  assert(determineOrder(d3, sizeof(d3)/sizeof(int)) == DESCENDING);

  assert(determineOrder(u1, sizeof(u1)/sizeof(int)) == UNDETERMINED);
  assert(determineOrder(u2, sizeof(u2)/sizeof(int)) == UNDETERMINED);
  assert(determineOrder(u3, sizeof(u3)/sizeof(int)) == UNDETERMINED);

  printf("Well done, you passed the tests, however you should make more of them\n");
}
