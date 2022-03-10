//Creating a decimal spiral 18/03/17

#include <stdio.h>

int main() {
    //Inputting user values
    int num;
    printf("Enter size: ");
    scanf("%d",&num);
    //Creating variables used to measure the length of the spiral
    int x,y,z;          //x=column, y=row, z=convergence variable
    int counter = 0;    //Counter for measuring length of spiral
    
    ////BLOCK A - MEASURING LENGTH OF SPIRAL////
    
    /* ODD and EVEN lines have different for loops governing their behaviour
     * ODD = For loop checks whether to "NOT" print a spiral
     * EVEN = For loop checks whether to print a spiral 
     * Likewise, the TOP and BOTTOM half of the spiral are also governed by different for loops
     * Thus TOP and BOTTOM halves of the spiral will be checked */
    for(y=1;y<=num;y++) {
        for(x=1;x<=num;x++) {       //Increments through each column in a given row
            if(y<=(num/2)+1) {      //Checking if top half of the spiral
                if((y+1)%2==0) {                        //ODD lines have their own rule set governed by their unique for loop
                    for(z=1; z<=y; z=z+2) {             //"z" increments in "2" from z=1 to z=y. This lets it check for multiple "x" values for the same "y" value
                        if((x==z-3) || (x==num-z+2)) {
                            break;                      //Breaks to end loop early and prevent "z" from exceeding "y" if it find its cannot print
                        } 
                    }
                    if(z>y) {                           //If the loop has not been broken early, it means the condition could not be satisfied. Thus it is performing the inverse below.
                        counter++;                      //ODD's for loop checks when not to print. Since that loop has maxed out, it knows to print through the above "if" statement
                    }
                } else if(y%2==0) {                     //EVEN uses a for loop to check when to print a spiral
                    for(z=0; z<=y-2; z=z+2) {
                        if((x==z-1) || (x==num-z)) {    //ODD and EVEN have different equations that govern them
                            counter++;                  //EVEN uses for loop to check IF there is a spiral
                            break;                      //Break loop early to prevent "z" from surpassing "y-2"
                        } 
                    }
                }
            } else if(y>(num/2)+1) {    //Checking bottom half of the spiral, which is governed by a different set of for loops
                if((y+1)%2==0) {
                    for(z=-y+num; z>=0; z=z-2) {
                        if((x==z) || (x==num-z+1)) {
                            break;
                        } 
                    }
                    if(z<0) {
                        counter++; 
                    }
                } else if(y%2==0) {
                    for(z=-y+num-1; z>=0; z=z-2) {
                        if((x==z+1) || (x==num-z)) {
                            counter++;
                            break;
                        } 
                    }
                }
            }
        }
    }
    ////BLOCK B - DETERMINING THE DECIMAL AT EACH POINT IN THE SPIRAL////
    
    /* After the counter has been reduced to below ten, it's final value will be that of the decimal -1 in (1,1)
     * -1 error is due to the spiral starting at 0 from the centre */
    counter = counter-1;
    /* After the code above has finished, it has incremented "counter"
     * The counter is only increased when there is a spiral, thus the "counter" increments to the length of the spiral
     * This length is then used to determine what the first decimal at (1,1) is */
    while(counter>=10) {    //The counter is continuously subtracted by 10, until it is less than 10
        counter = counter-10;
    }
    
    int decimal = counter;  //First decimal in the spiral
    int DECIMAL = decimal;  //DECIMAL variable is used, since decimal needs to be preserved permanently
    int print;              //Print=1 means to print a decimal, Print=0 means to print a dash
    int length;             //"length" will be used to measure the length of the spiral, from a given coordinate
    int up,down,left,right; //The variables up,down,left,right will be used to trace the spiral from a given coordinate
    int check;              //Used to determine whether the program has made an invalid move into a coordinate that isnt part of the spiral
    int x_scan=x,y_scan=y;  //The value of "x" and "y" need to be preserved for the "for" loops to function correctly. Thus x_scan and y_scan are used in the nested "for" loops when determining the length of the spiral
    
    //Raising or lowering the "print" flag depending on if the coordinate is on the spiral//
    for(y=1; y<=num; y++) {
        for(x=1; x<=num; x++) {
            /* This code block will flag print=1 if the coordinate is a spiral
             * If the coordinate is not part of the spiral print=0 
             * Note that this code block has been used before */
            if(y<=(num/2)+1) {
                if((y+1)%2==0) {
                    for(z=1; z<=y; z=z+2) {
                        if((x==z-3) || (x==num-z+2)) {
                            print=0;    //Print is used to determine whether there is a spiral
                            break; 
                        } 
                    }
                    if(z>y) {
                        print=1;
                    }
                } else if(y%2==0) {
                    for(z=0; z<=y-2; z=z+2) {
                        if((x==z-1) || (x==num-z)) {
                            print=1;
                            break;
                        } 
                    }
                    if(z>y-2) {
                        print=0;
                    }
                }
            } else if(y>(num/2)+1) {
                if((y+1)%2==0) {
                    for(z=-y+num; z>=0; z=z-2) {
                        if((x==z) || (x==num-z+1)) {
                            print=0;
                            break; 
                        } 
                    }
                        if(z<0) {
                            print=1;
                        }
                } else if(y%2==0) {
                    for(z=-y+num-1; z>=0; z=z-2) {
                        if((x==z+1) || (x==num-z)) {
                            print=1;
                            break;
                        } 
                    }
                    if(z<0) {
                        print=0;
                    }
                }
            }
            
            /* After the coordinate has been checked, the flag "print" will have a value 0/1
             * Print=1 means that the coordinate is on the spiral
             * Print=0 means that the coordinate is NOT on the spiral
             * When Print=1, a code block will run to determine how long the spiral is from that coordinate (x,y)
               to the beginning of the spiral at (1,1) */
            
            //If print=1, this means a decimal has to be printed//
            if(print==1) {
                //Determining the length of the spiral from coordinates (x,y) to (1,1)//
                /* Depending on which quadrant the coordinate is, the first move of the sequence will be different
                * Top-right    = Up 
                * Top-left     = Left
                * Bottom-left  = Down
                * Bottom-right = Right
                * This is because the sequence will always be Left>Down>Right>Up and we need to select the first move */
                left=0,down=0,right=0,up=0; //The movement variables need to be reset each time
                length=1;                   //Length variable needs to be reset each time
                DECIMAL = decimal;          //Reseting DECIMAL to decimal, so that on the next loop, the DECIMAL value counts down from decimal, which is the value at (1,1)
                if(y<=(num/2)+1) {          //The following code activates the first movement based on which quadrant (x,y) are in
                    if(x<=(num/2)+1) {
                        left=1;
                    } else if(x>(num/2)+1) {
                        up=1;
                    }
                } else if(y>(num/2)+1) {
                    if(x<=(num/2)+1) {
                        down=1;
                    } else if(x>(num/2)+1) {
                        right=1;
                    }
                }
                
                /* Storing the coordinates (x,y) into (x_scan,y_scan)
                 * Required as the original x and y values are needed in the for loops running this section
                 * A temporary x_scan and y_scan variable is used which can be altered without consequence to the program */
                x_scan=x, y_scan=y;
                
                /* This while loop is used to scan through the entire spiral from the coordinate (x,y) to (1,1)
                 * x_scan and y_scan are used since they allow for "x" and "y" to preserve their values
                 * The while loop will only run if the coordinates are not (1,1) */
                while(x_scan!=1 || y_scan!=1) { 
                    //Setting up the initial x_scan and y_scan values
                    if(left == 1) {
                        x_scan--;
                    } else if(down == 1) {
                        y_scan++;
                    } else if(right == 1) {
                        x_scan++;
                    } else if(up == 1) {
                        y_scan--;
                    }
                    //Sub x and y values to check if it is a spiral
                    if(y_scan<=(num/2)+1) {
                        if((y_scan+1)%2==0) {
                            for(z=1;z<=y_scan;z=z+2) {
                                if((x_scan==z-3) || (x_scan==num-z+2)) {
                                    check=0;
                                    break;  //Break to end loop early and prevent z>y
                                } 
                            }
                            if(z>y_scan) {
                                check=1;
                            }
                        } else if(y_scan%2==0) {
                            for(z=0;z<=y_scan-2;z=z+2) {
                                if((x_scan==z-1) || (x_scan==num-z)) {
                                    check=1;
                                    break;
                                } 
                            }
                            if(z>y_scan-2) {
                                check=0;
                            }
                        }
                    } else if(y_scan>num/2) {
                        if((y_scan+1)%2==0) {
                            for(z=-y_scan+num;z>=0;z=z-2) {
                                if((x_scan==z) || (x_scan==num-z+1)) {
                                    check=0;
                                    break; 
                                } 
                            }
                            if(z<0) {
                                check=1;
                            }
                        } else if(y_scan%2==0) {
                            for(z=-y_scan+num-1;z>=0;z=z-2) {
                                if((x_scan==z+1) || (x_scan==num-z)) {
                                    check=1;
                                    break;
                                } 
                            }
                            if(z<0) {
                                check=0;
                            }
                        }
                    }
                    if(x_scan>num || x_scan<0 || y_scan>num || y_scan<0) { //If the moved coordinate has exceeded the boundaries of the spiral, it will set check=0
                        check=0;
                    }
                    //Changing directions if the move didnt work
                    if(check==0){
                        if(left == 1) {
                            x_scan++;       //Resetting the x/y value back to its last valid coordinate
                            left=0,down=1;
                        } else if(down == 1) {
                            y_scan--;
                            down=0,right=1;
                        } else if(right == 1) {
                            x_scan--;
                            right=0,up=1;
                        } else if(up == 1) {
                            y_scan++;
                            up=0,left=1;
                        }
                    } else if(check==1) {   //If move did work, continue
                        length=length+1;
                    }
                }
                
                /* Now that the while loop has been completed, the length should be that from (x,y) to (1,1)
                 * To make use of this length, we need to convert length --> decimal value
                 * Done by taking DECIMAL(a clone of "decimal") and subtracting it by 1, "length" times 
                 * This is done using the for loop below, which reuses "counter" as its counter */
                for(counter=1; counter<length; counter++) {
                    if (DECIMAL == 0) { //If DECIMAL = 0, it needs to be reset to 9 for the next decimal
                        DECIMAL = 9;
                    } else {            //If DECIMAL != 0, it has not reached 0 yet and thus can be continually subtracted        
                        DECIMAL = DECIMAL-1;
                    }
                }
                printf("%d",DECIMAL);   //Printing out the decimal at that location
            } else if(print==0) {      
                printf("-");            //If print=0, then just print a "-"
            }
        }
        printf("\n");                   //This is directly below the for loop going through the x coordinates. Once it has gone through all x-coords for a given row, a new row will be started
    }
    
    return 0;
}
            
                

