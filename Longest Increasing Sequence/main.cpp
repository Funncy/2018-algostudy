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
int * board;
int * cache;

int solution(int x);
int solution2();

int main(){
    
    scanf("%d",&N);
    
    while(N--){
        
        scanf("%d",&WH);
        
        board = (int *)malloc(sizeof(int)*WH);
        cache = (int *)malloc(sizeof(int)*WH);
        
        memset(board,0,sizeof(int)*WH);
        memset(cache,-1,sizeof(int)*WH);
        
        for(int i=0;i<WH;i++)
            scanf("%d",&board[i]);
        
        printf("%d\n",solution2());
        
        free(board);
        free(cache);
    }
    
    return 0;
}

int solution2(){
    int ret = 0;
    int max = -1;
    
    for(int i=0;i<WH;i++){
        ret = solution(i);
        if(max == -1)
            max = ret;
        else{
            if(ret > max )
                max = ret;
        }
    }
    
    return max;
}

int solution(int x) {
    int ret = 1;
    int comp[500] = {0};
    int max = -1;
    
    if(x>= WH)
        return 0;
    
    if(cache[x]!=-1)
        return cache[x];
    
    for(int i=x+1; i<WH ; i++){
        if(board[i]> board[x]){
            if(max == -1)
                max = i;
            comp[i] = solution(i);
            if(comp[i] > comp[max]){
                //printf("change!! %d -> %d\n",max,i);
                //printf("%d %d\n",comp[i],comp[max]);
                max = i;
            }
        }
    }
    if(max == -1)
        cache[x] = 1;
    else
        cache[x] = comp[max] + 1;
    return cache[x];
}
