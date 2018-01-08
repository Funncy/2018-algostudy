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

int N;
bool isFriends[10][10];
bool Picnic[10];
int A,B;
int StudentN, FriendsN;
int ret = 0;
int solution();
int main() {
    
    scanf("%d",&N);
    
    while(N--){
        for(int i=0;i<10;++i)
        memset(isFriends[i],0,sizeof(bool)*10);
        memset(Picnic,0,sizeof(bool)*10);
        ret = 0;
        scanf("%d %d",&StudentN,&FriendsN);
        for(int i=0;i<FriendsN;i++){
            scanf("%d %d",&A,&B);
            isFriends[A][B] = 1;
            isFriends[B][A] = 1;
        }
        solution();
        
        printf("%d\n",ret);
    }
    
    return 0;
}

int solution(){

    int FirstAsshole = -1;
 //   int SecondAsshole = 0;
    
    for(int i=0;i<StudentN;i++)
        if(Picnic[i]==0){
            FirstAsshole = i;
            break;
        }
                
        
    
    if(FirstAsshole == -1){
        return 1;
    }
    
    for(int i=FirstAsshole+1; i<StudentN; i++){
        if(isFriends[FirstAsshole][i]==1 && Picnic[i]==0 ){
            Picnic[FirstAsshole] = 1;
            Picnic[i] = 1;
            ret += solution();
            Picnic[FirstAsshole] = 0;
            Picnic[i] = 0;
        }
    }
    
    
    return 0;
}
