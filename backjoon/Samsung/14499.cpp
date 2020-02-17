#include <stdio.h>
#include <iostream>

using namespace std;

int N,M; // map size
int x,y; // dice x,y position
int K;   // command count
int R,C; // R: north count, C: south count
int map[20][20];

struct dice_map
{
   int bottom = 0;
   int upper = 0;
   int right = 0;
   int left = 0;
   int front = 0;
   int back = 0;
};

dice_map s;

void data()
{
   scanf("%d",&N); // y axis
   scanf("%d",&M); // x axis
   
   scanf("%d",&x); // dice x_position
   scanf("%d",&y); // dice y_position
   
   scanf("%d",&K); // command total count
}

void map_data()
{
   for(int i=0;i<N;i++)
      for(int j=0;j<M;j++){
         scanf("%d",&map[j][i]);
      }
}

bool isInline(int position){
   
   switch (position){
       case 1 : 
        if(x+1<M){
         x = x+1;
         return true;

        }
        else{
         return false;

        }
         break;
        case 2:
               if(x-1>=0){
         x = x-1;
return true;
               }
        else{
         return false;

        }
         break;
case 3: 

      if(y-1>=0){
         y = y-1;

    return true;
      }
      else
         return false;
    break;
    case 4 : 
          if(y+1 < N){
         y = y+1;

    return true;
          }
      else
         return false;
         break;
    
   }
  
   
   return false;
}

void dice_map_change(int direction){
   
   int p;
   p = s.bottom;
   
   if(direction == 4){   
      s.bottom = s.front; //front south
      s.front = s.upper;
      s.upper = s.back;
      s.back = p;
      //printf("[South]\n");
      //printf("bot = %d, up = %d, fron = %d, bac = %d, rig = %d, lef = %d\n",s.bottom,s.upper,s.front,s.back,s.right,s.left);
   }
   if (direction == 3){
      s.bottom = s.back;
      s.back = s.upper;
      s.upper = s.front;
      s.front = p;
      //printf("[North]\n");
      //printf("bot = %d, up = %d, fron = %d, bac = %d, rig = %d, lef = %d\n",s.bottom,s.upper,s.front,s.back,s.right,s.left);
   
   }
   if (direction == 2){
      s.bottom = s.left;
      s.left = s.upper;
      s.upper = s.right;
      s.right = p;
      //printf("[West]\n");
      //printf("bot = %d, up = %d, fron = %d, bac = %d, rig = %d, lef = %d\n",s.bottom,s.upper,s.front,s.back,s.right,s.left);
   
   }
   if(direction==1){
      s.bottom = s.right;
      s.right = s.upper;
      s.upper = s.left;
      s.left = p;   
      //printf("[East]\n");
      //printf("bot = %d, up = %d, fron = %d, bac = %d, rig = %d, lef = %d\n",s.bottom,s.upper,s.front,s.back,s.right,s.left);
   
   }
   
}

void printing_value(){
   if(map[x][y] == 0){
      map[x][y] = s.bottom;
   }   
   else{
      s.bottom = map[x][y];
      map[x][y] = 0;
   }
   //printf("x = %d, y = %d\n",x,y);
   //printf("\tbot = %d, up = %d, fron = %d, bac = %d, rig = %d, lef = %d\n",s.bottom,s.upper,s.front,s.back,s.right,s.left);
   //printf("(after dice)[x,y] = %d, %d",x,y);
   //printf("\n\n");
   printf("%d\n",s.upper);
}

int main(){

   int tmp = 0;
   bool k=false;
   data();
   map_data();
   
   for(int t=0;t<K;t++)
   {
      scanf("%d",&tmp);
      
      k = isInline(tmp);
      
      //printf("\t bot = %d, up = %d, fron = %d, bac = %d, rig = %d, lef = %d\n",s.bottom,s.upper,s.front,s.back,s.right,s.left);
   
      if(k){
         dice_map_change(tmp);
         //printf("map[x][y] = %d\n",map[x][y]);
         printing_value();
         
      }
   }
   
   return 0;
}