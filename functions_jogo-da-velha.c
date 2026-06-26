#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int intInput(const char *mensagem){
    int valor;

    while(1){
        printf("%s", mensagem);

        if(scanf("%d", &valor) == 1){
            while(getchar() != '\n');
            return valor;
        }

        printf("Entrada invalida!\n");

        while(getchar() != '\n');
    }
}

int verifyOX(char caractere){
	if(caractere == 'O' || caractere == 'X'){
		return 1;
	}else{
		return 0;
	}
}

char verifyWinner(char t[3][3]) {

    for (int i = 0; i < 3; i++) {
        if (t[i][0] != ' ' && t[i][0] == t[i][1] && t[i][1] == t[i][2]) {
            return t[i][0];
        }
    }

    for (int j = 0; j < 3; j++) {
        if (t[0][j] != ' ' && t[0][j] == t[1][j] && t[1][j] == t[2][j]) {
            return t[0][j];
        }
    }


    if (t[0][0] != ' ' && t[0][0] == t[1][1] && t[1][1] == t[2][2]) {
        return t[0][0];
    }


    if (t[0][2] != ' ' && t[0][2] == t[1][1] && t[1][1] == t[2][0]) {
        return t[0][2];
    }


    return ' ';
}

void computerMove(char t[3][3], char boss_char){
    int linha, coluna;

    while (1) {
        linha = rand() % 3;
        coluna = rand() % 3;

        if (t[linha][coluna] == ' ') {
            t[linha][coluna] = boss_char;
            break; 
        }
    }
}

void showGame(char game[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("| %c ", game[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}