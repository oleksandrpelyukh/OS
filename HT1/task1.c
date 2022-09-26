#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void MessageBox(int first, int second, int third, int money, int flag){
  
  printf("\n");
    
  if(flag == 0){
    printf("Current combination: %d%d%d\n", first, second, third);
    printf("Current balance: %d\n", money);
  }
  
  if(flag == 1){
    printf("Current combination: %d%d%d\n", first, second, third);
    printf("You've hit the jackpot, congratulations! Game over\n");
  }
  
  if(flag == -1){
    printf("It looks like you are bankrupt. Game over.\nCurrent balance: %d\n", money);
  }  
}

void CombinationGenerate(int mas[]){
  
  int i;
  
  for(i = 0; i < 3; i++){mas[i] = (rand() %(7 - 0 + 1)) + 0;}
}

int main(){

  int mas[3];  
  int money = 5000;
  int flag = 0;
  
  srand(time(NULL));
    
  while(money >= 0){

    CombinationGenerate(mas);
    money = money - 100;
    
    if(money <= 0){
      flag = -1;
      MessageBox(mas[0], mas[1], mas[2], money, flag);
      break;
    }
        
    if (mas[0] == 6 && mas[1] == 6 && mas[2] == 6){
      money = money - 100;
      MessageBox(mas[0], mas[1], mas[2], money, flag);
      printf("Oops: -100 !\n");
    }
    
    else if (mas[0] == 7 && mas[1] == 7 && mas[2] == 7){
      money += 200000;
      flag = 1;
      MessageBox(mas[0], mas[1], mas[2], money, flag);
      break;
    }
    
    else if(mas[0] == mas[1] && mas[0] == mas[2]){
      money+=500;
      MessageBox(mas[0], mas[1], mas[2], money, flag);
      printf("Victory: +500 !\n");
    }
    
    else if(mas[0] == 5 && mas[1]!=mas[0] && mas[2]!=mas[0]){
      money+=100;
      MessageBox(mas[0], mas[1], mas[2], money, flag);
      printf("Victory: +100 !\n");
    }
    
    else if(mas[0] == 7 && mas[1]!=mas[0] && mas[2]!=mas[0]){
      money+=100;
      MessageBox(mas[0], mas[1], mas[2], money, flag);
      printf("Victory: +100 !\n");
    }
    
    else if(mas[0] == mas[1] &&  mas[1] == 5){
      money+=200;
      MessageBox(mas[0], mas[1], mas[2], money, flag);
      printf("Victory: +200 !\n");
    }
    
    else if(mas[0] == mas[1] &&  mas[1] == 7){
      money+=200;
      MessageBox(mas[0], mas[1], mas[2], money, flag);
      printf("Victory: +200 !\n");
    }
    
    else{
      MessageBox(mas[0], mas[1], mas[2], money, flag);
    }
  }
  
  return 0;
}
