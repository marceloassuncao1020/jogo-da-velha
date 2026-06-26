#include <stdio.h>
#include <string.h>
#include "functions_jogo-da-velha.c"

int main(int argc, char const *argv[])
{
	char player = ' ';
	char input;
	char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	int linha;
	int coluna;
	char boss_char;
	int total_jogadas = 0;
	srand(time(NULL));

	if(argc > 3){
	    printf("Uso: jogo [X|O] [auto]\n");
	    return 1;
	}

	if(argc >= 2 && verifyOX(argv[1][0])){
		player = argv[1][0];

	}else{
		while (!verifyOX(player)) {
		    printf("digite seu personagem (X ou O): ");
		    scanf(" %c", &input);

		    if(verifyOX(input)){
		        player = input;

		    } else {
		        printf("Opcao invalida! Tente novamente.\n");
		    }
		}
	}

	if(player == 'X'){boss_char = 'O';}
	if(player == 'O'){boss_char = 'X';}

	while(verifyWinner(game) == ' ' && total_jogadas < 9){

		if(argc == 3 && strcmp(argv[2], "auto") == 0){
			computerMove(game, player);
			total_jogadas++;

			printf("-------%c------\n\n", player);
			showGame(game);
		}else{
			linha = intInput("digite a linha de sua jogada: ");
			coluna = intInput("digite a coluna de sua jogada: ");

			if(linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && game[linha][coluna] == ' '){

				game[linha][coluna] = player;		
				total_jogadas++;

				printf("-------%c------\n\n", player);
				showGame(game);

			} else {
		    	printf("\nJogada invalida! Tente novamente em uma casa vazia.\n\n");
		    	continue;
			}
		}

		if (verifyWinner(game) != ' ' || total_jogadas >= 9) {
			break;
		}

		total_jogadas++;
		computerMove(game, boss_char);

		printf("-------%c------\n\n", boss_char);

		showGame(game);

	}

	char winner = verifyWinner(game);

	printf("--------------------- \n");
	if(winner == 'X'){
	    printf("O jogador 1 (X) ganhou\n");
	}else if(winner == 'O'){
	    printf("O jogador 2 (O) ganhou\n");
	}else{
	    printf("O jogo terminou sem vencedores\n");
	}

	printf("\n\nFeito por Marcelo Rigotti");
	return 0;
}