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
            for(int j=0;j<WH;j++){
                scanf("%d",&board[i][j]);
            }
        }
        
        if(solution(0,0)>=1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        
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
    
    if(currentData == 0)
        return 1;
    
    
    
    if(x+currentData < WH){
        
        cache[x][y] = solution(x+currentData,y);
        ret += cache[x][y];
    }
    
    if(y+currentData < WH){
        cache[x][y] = solution(x,y+currentData);
        ret += cache[x][y];

    }
    
    
    return ret;
}
