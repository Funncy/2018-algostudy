//
//  main.cpp
//  algo
//
//  Created by HJ Kim on 2018. 1. 8..
//  Copyright © 2018년 HJ Kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>

int N;
int WH;
int ** board;
int ** cache;

int solution(int x,int y);


int main(){
    
    scanf("%d",&N);
    
    while(N--){
        
        scanf("%d",&WH);
        
        board = (int **)malloc(sizeof(int*)*WH);
        cache = (int **)malloc(sizeof(int*)*WH);
        for(int i=0;i<WH;i++){
            board[i] = (int*)malloc(sizeof(int)*WH);
            cache[i] = (int*)malloc(sizeof(int)*WH);
            memset(board[i],0,sizeof(int)*WH);
            memset(cache[i],-1,sizeof(int)*WH);
        }
        
        for(int i=0;i<WH;i++){
            for(int j=0;j<=i;j++){
                scanf("%d",&board[i][j]);
            }
        }
      
        printf("%d\n",solution(0, 0));
        free(board);
        free(cache);
    }
    
    return 0;
}

int solution(int x,int y) {
    int ret = 0;
    
    if(cache[x][y]!=-1)
        return cache[x][y];
    
    
    int currentData = board[x][y];
    
    if(x+1 < WH){
        
    
    
    int tmp=0,tmp2=0;
    
    tmp = currentData + solution(x+1,y);
    tmp2 = currentData + solution(x+1,y+1);
    
    if(tmp>tmp2)
        cache[x][y] = tmp;
    else
        cache[x][y] = tmp2;
        
        return cache[x][y];
    
    }
    return currentData;
    
   // return ret;
}
