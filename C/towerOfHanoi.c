//
//  main.c
//  towerOfHanoi
//
//  Created by batuhanyenidunya on 9.12.2019.
//  Copyright © 2019 batuhanyenidunya. All rights reserved.
//

#include <stdio.h>

void moveDisc(char base, char target);
void hanoi(int numOfDiscs, char base, char helper, char target);

int main() {
    hanoi(4, 'A', 'B', 'C');
    return 0;
}

void moveDisc(char base, char target){
    printf("Move one disc from %c to %c\n",base,target);
}

void hanoi(int numOfDiscs, char base, char helper, char target){
    if (numOfDiscs == 0) {
        //end of recursion
    }else{
        hanoi(numOfDiscs-1,base, target, helper);
        moveDisc(base, target);
        hanoi(numOfDiscs-1, helper, base, target);
    }
}
