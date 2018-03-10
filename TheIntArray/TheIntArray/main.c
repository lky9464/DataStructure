//
//  main.c
//  TheIntArray
//
//  Created by LeeKY on 10/03/2018.
//  Copyright © 2018 MobileX. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int Array1[] = {1, 2, 3, 4, 5};
    int Array2[5] = {6, 7, 8, 9, 10};
    int Array3[][3] = {11, 22, 33, 44, 55, 66};
    
    printf("%d %d %d\n", Array1[0], Array2[0], Array3[1][1]);
    
    return 0;
}
