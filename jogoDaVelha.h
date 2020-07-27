#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include <time.h>

using namespace std;

SDL_Texture *carregaImagem(const char *imagem, SDL_Renderer *renderizador);

void imprimeMapa(SDL_Renderer *renderizador, SDL_Texture *tabTex);

void escolheJogada(int tabuleiro[3][3], int &jogador);

void imprimeJogada(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *xTex, SDL_Texture *oTex, SDL_Rect matrizPosicoes[3][3]);

bool verificaGanhouLinha(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Rect resultadoDestino, bool termina);

bool verificaGanhouColuna(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Rect resultadoDestino, bool termina);

bool verificaDiagonal1(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Rect resultadoDestino, bool termina);

bool verificaDiagonal2(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Rect resultadoDestino, bool termina);

bool verificaEmpatou(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *gameOver, SDL_Rect resultadoDestino, bool termina);

bool verificaFinal(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Texture *gameOver);


#endif // JOGODAVELHA_H
