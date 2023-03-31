#include<stdio.h>
char type[5][4] = {
    {"   "},
    {"  |"},
    {"|  "},
    {"| |"},
    {" - "},
    };
char Num[10][5] = {
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
void PrintNum(char s[], int n) {//n=4
    int a, b, c, tn;
    for(a = 0; a < 5; a++) {
        if(a == 0 || a == 2 || a == 4) tn = 1;//en esta parte evaluamos la parte del numero(columnas)
        else tn = n;//si son filas las que hay que aumentar
        while(tn--) {
            for(b = 0; s[b]; b++) {//la condicion s[b] recorre el arreglo hasta que encuentre un espacio vacio o "false"
                if(s[b] == ' ') putchar(' ');

                putchar(type[Num[s[b] - '0'][a]][0]);//imprime la primera columna de la matriz type

                for(c = 0; c < n; c++)//imprime los espacios o guiones en este caso los espacios
                    putchar(type[Num[s[b] - '0'][a]][1]);

                putchar(type[Num[s[b] - '0'][a]][2]);//imprime espacio en blanco

                if(s[b+1] != '\0') putchar(' ');//imprime espacio en blanco entre los numeros
            }
            puts("");
        }
    }
}
main() {
    int n;//n el tamaño
    char s[20];//s guarda el numero
    while(scanf("%d %s", &n, s) == 2) {
        if(n == 0)
            break;
        PrintNum(s, n);
        puts("");
    }
    return 0;
}
