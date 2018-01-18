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

int solution(int n);

int N;
int caseN;

int cache[100];

int main(){
    
    scanf("%d",&N);
    int tmp=0;
    
    while(N--){
        scanf("%d",&caseN);
        
        memset(cache,-1,sizeof(int)*100);
        
        tmp =solution(0);
        printf("%d\n",tmp);
        
    }
    
    return 0;
}


int solution(int n) {
    int ret =0;
    
    
    if(n == caseN)
        return 1;
    else if(n > caseN)
        return 0;
    
    if(cache[n] != -1)
        return cache[n];
    
    
    ret += solution(n + 1);
    ret += solution(n + 2);
    
    cache[n] = ret % 1000000007;
    
    return cache[n];
}
