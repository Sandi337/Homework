#include <stdio.h>
//#include <math.h> //sqrt :double
#define MAX_N 1000

int n ,r;
int x[MAX_N], y[MAX_N];//node i : (x[i],y[i])

int connect(int i,int j){
    int dx = x[i]- x[j];
    int dy = y[i]- y[j];
    return (dx * dx + dy * dy) <= (r * r);
}

int visited[MAX_N]; //init to 0
//we dont want walk onto node that has visited

/*
    return Number of node found from "now"
*/
//void dfs(int pa, int now){
int dfs(int now){
    visited[now] = 1;
    int res = 1;
    for(int i = 0; i < n ;i++){
        if(visited[i]) continue;
        //if(i == pa) continue;
        //if(i == now) continue;
        if(!connect(now, i)) continue;
        res += dfs(i);
        //dfs(now, i);
    }
    return res;
} 

int main(){
    //memset(visited, 0 , sizeof(visited));
    scanf("%d%d", &n, &r);
    for(int i = 0; i <n ; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    int single = 0,multi = 0;
    for(int i = 0; i <n ; i++){
        if(visited[i]) continue;
        if(dfs(i) == 1){
            ++single;
        }else{
            ++multi;
        } 
    }
    printf("%d %d\n", single, multi);
}