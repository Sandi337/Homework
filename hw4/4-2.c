#include <stdio.h>

int main(){
  int n, m ;//5,3
  scanf("%d %d",&n ,&m);
  int request[200005] = {0};
  int used[200005] = {0};

  for (int i = 1; i <= m; i++){

    scanf("%d",&request[i]);
  }

  for(int i = m; i > 0; i--){
    if(used[request[i]] == 0){
      printf("%d\n", request[i]);
      used[request[i]] = 1;
    }
  }

  for (int i = 1;i <= n; i++){
    if(used[i] == 0){
      printf("%d\n",i);
    }
  }

}