//
//  main.c
//  FindElement
//
//  Created by LeeKY on 10/03/2018.
//  Copyright © 2018 MobileX. All rights reserved.
//

#include <stdio.h>

// 순차 탐색(Sequential search) 알고리즘
int main()
{
    int arr[]={12,23,78,98,67,56,45,19,65,9},key,i,flag=0;
    
    printf("배열 arr의 멤버 \n");
    for(i=0;i<10;i++)
        printf("%4d",arr[i]);
    
    printf("\narr 배열에서 찾고자하는 수를 입력하세요 : ");
    scanf("%d",&key);
    
    for(i=0;i<10;i++) {
        if(arr[i] == key){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
    }
    
    if(flag==1)
        printf("\n %d(은)는 배열에 있음\n",key);
    else
        printf("\n %d(은)는 배열에 없음\n",key);
    
    return 0;
}
