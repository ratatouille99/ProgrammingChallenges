#include <stdio.h>
#include <stdlib.h>

char nombre[100][20];
char table[100][250][250];
char board[250][250];
char comands[20];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void clearBoard(int n, int m);
void sizeBoard();
void paintBoard();
void vertical();
void horizontal();
void rectangle();
void fillRegion(int n, int m);
void submit(char nombre[], int n, int m, int t);

int main()
{
    int n, m, t = 0;
    int exit = 1;

    //scanf("%s", comands);//Ponemos %s por que estamos ingresando una cadena de texto

    while(scanf("%s", comands)){
        char option = toupper(comands[0]);

        if(option == 'X') break;

        if(option == 'I'){
            m = comands[2] - '0';
            n = comands[1] - '0';
            clearBoard(n,m);
        }

        switch(option){
            case 'C': clearBoard(n,m); break;
            case 'L': paintBoard(); break;
            case 'V': vertical(); break;
            case 'H': horizontal(); break;
            case 'K': rectangle(); break;
            case 'F': fillRegion(n,m); break;
            case 'S': scanf("%s",nombre[t]);
                      submit(nombre, n, m,t);
                      t++; printf("\n"); break;
            default: break;
        }

        for(int i = 0; i < 20; i++) comands[i] = '0';
    }

    for(int k = 0; k < t; k++){
        for(int r = 0; nombre[k][r]; r++) printf("%c", nombre[k][r]);

        printf("\n");

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) printf("%c", table[k][i][j]);
            printf("\n");
        }
    }



    return 0;
}

void clearBoard(int n, int m){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) board[i][j] = '0';
    }
}

void paintBoard(){
    char color = comands[3];
    int x = comands[1] - '0';
    int y = comands[2] - '0';

    board[y-1][x-1] = color;
}

void vertical(){
    char color =  comands[4];
    int x = (comands[1] - '0') - 1;
    int y1 = (comands[2] - '0') - 1;
    int y2 = (comands[3] - '0') - 1;

    for(int i = y1; i < y2+1; i++){
        for(int j = x; j < x+1; j++) board[i][j] = color;
    }
}

void horizontal(){
    char color =  comands[4];
    int x1 = (comands[1] - '0') - 1;
    int x2 = (comands[2] - '0') - 1;
    int y = (comands[3] - '0') - 1;

    for(int i = y; i < y + 1; i++){
        for(int j = x1; j < x2+1; j++) board[i][j] = color;
    }
}

void rectangle(){
    char color = comands[5];
    int x1 = (comands[1] - '0') - 1;
    int y1 = (comands[2] - '0') - 1;
    int x2 = (comands[3] - '0') - 1;
    int y2 = (comands[4] - '0') - 1;

    for(int i = x1; i < x2 + 1; i++){
        for(int j = y1; j < y2 + 1; j++) board[i][j] = color;
    }
}

void fillRegion(int n, int m){
    char color =  comands[3];
    int x = (comands[1] - '0') - 1;
    int y = (comands[2] - '0') - 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == color || board[i][j] == '0') board[i][j] = color;
        }
    }
    /*for(int i = 0; i < 8; i++){
        int x1 = dx[i] + x;
        int y1 = dy[i] + y;

        if(x1>= 0 && x1 < m && y1 >= 0 && y1 < n && board[x1][y1] == '0'){
            board[x1][y1] = color;
        }
    }*/
}

void submit(char nombre[], int n, int m, int t){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) table[t][i][j] = board[i][j];
    }
}
