#include <stdio.h>
#include <assert.h>

#include "functions_jogo-da-velha.c" 

void test_verify_ox() {
    assert(verifyOX('X') == 1);
    assert(verifyOX('O') == 1);
    assert(verifyOX('Z') == 0);
    assert(verifyOX(' ') == 0);
    printf("[PASS] test_verify_ox\n");
}

void test_verificarGanhador_linha() {
    char tabuleiro[3][3] = {
        {'X', 'X', 'X'},
        {' ', 'O', ' '},
        {' ', ' ', 'O'}
    };
    assert(verifyWinner(tabuleiro) == 'X');
    printf("[PASS] test_verificarGanhador_linha\n");
}

void test_verificarGanhador_coluna() {
    char tabuleiro[3][3] = {
        {'O', 'X', ' '},
        {'O', ' ', 'X'},
        {'O', ' ', ' '}
    };
    assert(verifyWinner(tabuleiro) == 'O');
    printf("[PASS] test_verificarGanhador_coluna\n");
}

void test_verificarGanhador_diagonal() {
    char tabuleiro[3][3] = {
        {'X', ' ', 'O'},
        {' ', 'X', ' '},
        {'O', ' ', 'X'}
    };
    assert(verifyWinner(tabuleiro) == 'X');
    printf("[PASS] test_verificarGanhador_diagonal\n");
}

void test_verificarGanhador_empate() {
    char tabuleiro[3][3] = {
        {'X', 'O', 'X'},
        {'X', 'O', 'O'},
        {'O', 'X', 'X'}
    };
    assert(verifyWinner(tabuleiro) == ' ');
    printf("[PASS] test_verificarGanhador_empate\n");
}

void test_bossMove() {
    char tabuleiro[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'O', 'X', ' '}
    };
    
    computerMove(tabuleiro, 'O');
    
    assert(tabuleiro[2][2] == 'O');
    printf("[PASS] test_bossMove\n");
}

void test_showGame() {
    char tabuleiro[3][3] = {
        {'X', 'O', ' '},
        {' ', 'X', ' '},
        {'O', ' ', 'X'}
    };

    printf("[INFO] Saida de showGame:\n");
    showGame(tabuleiro);
}

int main() {

    test_verify_ox();
    test_verificarGanhador_linha();
    test_verificarGanhador_coluna();
    test_verificarGanhador_diagonal();
    test_verificarGanhador_empate();
    test_bossMove();
    test_showGame();

    printf("\nTodos os testes passaram com sucesso!\n");
    return 0;
}
