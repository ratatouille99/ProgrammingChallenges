#include <stdio.h>
#include <stdlib.h>

char patterns[5][3] = {
    {"   "},{"  |"},{"|  "},{"| |"},{" - "},
    };
char numbers[10][5] = {
    {4,3,0,3,4},/*0*/
    {0,1,0,1,0},/*1*/
    {4,1,4,2,4},/*2*/
    {4,1,4,1,4},/*3*/
    {0,3,4,1,0},/*4*/
    {4,2,4,1,4},/*5*/
    {4,2,4,3,4},/*6*/
    {4,1,0,1,0},/*7*/
    {4,3,4,3,4},/*8*/
    {4,3,4,1,4}/*9*/
};

void Draw(char n[], int s);

int main()
{
    int s;
    char n[10];

    while(scanf("%d %s", &s,n)){
        if(n == 0) break;

        Draw(n,s);
        puts("");
    }


    return 0;
}

void Draw(char n[], int s){
    int a, b, c, tn;

    for(a = 0; a < 5; a++){
        if(a == 0 || a == 2 || a ==4) tn = 1;
        else tn = s;

        while(tn--){
            for(b = 0; n[b]; b++){
                if(n[b] == ' '){
                    putchar(' ');
                    continue;
                }

                putchar(patterns[numbers[n[b] - '0'][a]][0]);

                for(c = 0; c < s; c++){
                    putchar(patterns[numbers[n[b]- '0'][a]][1]);
                }

                putchar(patterns[numbers[n[b]- '0'][a]][2]);

                if(n[b+1] != '\0') putchar(' ');
            }
            puts("");
        }
    }

}
