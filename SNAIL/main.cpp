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
int M;
int Deep;
double board[1001][1001];

double solution(int Day,int CDeep);


int main(){
    
    scanf("%d",&N);
    
    while(N--){
        
        scanf("%d %d",&Deep,&M);
        
        for(int i=0; i<1001; i++)
            for(int j=0; j<1001; j++)
                board[i][j] = -1;
        
        printf("%.10lf\n",solution(0,0));
        
    }
    
    return 0;
}


double solution(int Day,int CDeep) {
    double ret = 0.0;
    
    //DP 종료 조건
    if(board[Day][CDeep] != -1.0){
        return board[Day][CDeep];
    }
    
    //종료 조건 장마기간 끝남
    if(CDeep >= Deep)
        return 1;
    else if(Day>= M)
        return 0;
    
    ret += 0.75 * (solution(Day + 1, CDeep + 2));
    ret += 0.25 * (solution(Day + 1, CDeep + 1));
    
    board[Day][CDeep] = ret;
    
    return ret;
}
