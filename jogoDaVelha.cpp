#include "jogoDaVelha.h"

SDL_Texture *carregaImagem(const char *imagem, SDL_Renderer *renderizador){
    SDL_Surface *img = SDL_LoadBMP(imagem);
    if(img == nullptr){
        cout << "Erro no carregamento da Imagem!" << endl;
    }
    SDL_Texture *textura = SDL_CreateTextureFromSurface(renderizador, img);
    SDL_FreeSurface(img);
    return textura;
}

void imprimeMapa(SDL_Renderer *renderizador, SDL_Texture *tabTex){
    SDL_RenderClear(renderizador);

    SDL_Rect tabOrigem{0, 0, 570, 605};
    SDL_Rect tabDest{0, 0, 570, 605};

    SDL_RenderCopy(renderizador, tabTex, &tabOrigem, &tabDest);
}

void escolheJogada(int tabuleiro[3][3], int &jogador){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_MOUSEBUTTONDOWN: {
            int x, y;
            SDL_GetMouseState(&x, &y);

            int indiceColuna = x / 200;
            int indiceLinha = y / 200;
            if(tabuleiro[indiceLinha][indiceColuna] == -1){
                jogador++;
                tabuleiro[indiceLinha][indiceColuna] = jogador % 2;
            }
            break;

        }
        default:
            break;
        }

    }
}

void imprimeJogada(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *xTex, SDL_Texture *oTex, SDL_Rect matrizPosicoes[3][3]){

    SDL_Rect jogadaOrigem{0, 0, 71, 71};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] != -1) {
                auto posicao = matrizPosicoes[i][j];
                auto tex = tabuleiro[i][j] == 0 ? xTex : oTex;
                SDL_RenderCopy(renderizador, tex, &jogadaOrigem, &posicao);
            }
        }
    }
}

bool verificaGanhouLinha(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Rect resultadoDestino, bool termina){
    int cont = 0, cont2 = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(tabuleiro[i][j] == 0){
                cont++;
            }
            if(tabuleiro[i][j] == 1){
                cont2++;
            }
            if (cont == 3){
                SDL_RenderCopy(renderizador, oneWins, NULL, &resultadoDestino);
                termina = true;
            }
            if(cont2 == 3){
                SDL_RenderCopy(renderizador, twoWins, NULL, &resultadoDestino);
                termina = true;
            }
        }
        cont = 0;
        cont2 = 0;
    }
    return termina;
}

bool verificaGanhouColuna(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Rect resultadoDestino, bool termina){
    int cont = 0;
    int cont2 = 0;
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            if(tabuleiro[i][j] == 0){
                cont++;
            }
            if(tabuleiro[i][j] == 1){
                cont2++;
            }
            if (cont == 3){
                SDL_RenderCopy(renderizador, oneWins, NULL, &resultadoDestino);
                termina = true;
            }
            if(cont2 == 3){
                SDL_RenderCopy(renderizador, twoWins, NULL, &resultadoDestino);
                termina = true;
            }
        }
        cont = 0;
        cont2 = 0;
    }
    return termina;
}

bool verificaDiagonal1(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Rect resultadoDestino, bool termina){
    int cont = 0;
    int cont2 = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i+j == 2){
                if(tabuleiro[i][j] == 0){
                    cont++;
                }
                if(tabuleiro[i][j] == 1){
                    cont2++;
                }
                if (cont == 3){
                    SDL_RenderCopy(renderizador, oneWins, NULL, &resultadoDestino);
                    termina = true;

                }
                if(cont2 == 3){
                    SDL_RenderCopy(renderizador, twoWins, NULL, &resultadoDestino);
                    termina = true;
                }
            }

        }
    }

    return termina;
}

bool verificaDiagonal2(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Rect resultadoDestino, bool termina){
    int cont = 0;
    int cont2 = 0;

    for (int i = 0; i < 3; i++) {
        if(tabuleiro[i][i] == 0){
            cont++;
        }
        if(tabuleiro[i][i] == 1){
            cont2++;
        }
        if (cont == 3){
            SDL_RenderCopy(renderizador, oneWins, NULL, &resultadoDestino);
            termina = true;
        }
        if(cont2 == 3){
            SDL_RenderCopy(renderizador, twoWins, NULL, &resultadoDestino);
            termina = true;
        }
    }

    return termina;
}

bool verificaEmpatou(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *gameOver, SDL_Rect resultadoDestino, bool termina){
    int preenchido = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(tabuleiro[i][j] != -1){
                preenchido++;
            }
            if(preenchido == 9 and termina == false){
                SDL_RenderCopy(renderizador, gameOver, NULL, &resultadoDestino);
                termina = true;
            }
        }
    }

    return termina;
}

bool verificaFinal(int tabuleiro[3][3], SDL_Renderer *renderizador, SDL_Texture *oneWins, SDL_Texture *twoWins, SDL_Texture *gameOver){
    bool termina = false;
    SDL_Rect resultadoDestino{105, 192, 360, 222};

    termina = verificaGanhouLinha(tabuleiro, renderizador, oneWins, twoWins, resultadoDestino, termina);
    termina = verificaGanhouColuna(tabuleiro, renderizador, oneWins, twoWins, resultadoDestino, termina);
    termina = verificaDiagonal1(tabuleiro, renderizador, oneWins, twoWins, resultadoDestino, termina);
    termina = verificaDiagonal2(tabuleiro, renderizador, oneWins, twoWins, resultadoDestino, termina);
    termina = verificaEmpatou(tabuleiro, renderizador, gameOver, resultadoDestino, termina);

    return termina;
}
