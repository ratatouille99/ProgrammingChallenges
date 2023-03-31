#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int lista(int n, int *nums);
int draw(int s, int *nums, int size);

int main()
{
    char patterns[10][5][3] = {
        {" - ",
         "   ",
         "| |",
         "   ",
         " - "
        },
        {"   ",
         " | ",
         "   ",
         " | ",
         "   "
         },

        {" - ",
         "  |",
         " - ",
         "|  ",
         " - "
         },

         {" - ",
          "  |",
          " - ",
          "  |",
          " - "
         },

         {"   ",
          "| |",
          " - ",
          "  |",
          "   "
         },

         {" - ",
          "|  ",
          " - ",
          "  |",
          " - "
          },

         {" - ",
          "  |",
          " - ",
          "| |",
          " - "
         },

         {" - ",
          "   ",
          "  |",
          "   ",
          "  |"
         },

         {" - ",
          "| |",
          " - ",
          "| |",
          " - "
         },

         {" - ",
          "| |",
          " - ",
          "  |",
          " - "
         }

         };

    int s, size = 0;
    int nums[8] = {10,10,10,10,10,10,10,10};
    ll n;

    scanf("%d %d", &s,&n);

    size = lista(n,nums);
123


    for(int i = 8 - size; i < 8; i++){
        int num = nums[i];
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 3; k++){
                if(patterns[num][j][k] == "-"){
                    for(int l = 0; l < s; l++) printf("%c", patterns[num][j][k]);
                }
                else printf("%c", patterns[num][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}

int lista(int n, int *nums){
    int x = n, tam = 0;

    while(x > 0){
        for(int i = 7; i >= 0; i--){
            if(x > 0){
                nums[i] = x % 10;
                x /= 10;
                tam ++;
            }
            else break;
        }
    }

    return tam;
}
