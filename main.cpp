#include "jogoDaVelha.h"

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING); // Inicializa toda a biblioteca

    SDL_Window *janela = SDL_CreateWindow("Janela SDL", // Cria janela
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     568,575,
                     0);

    SDL_Renderer *renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED); // Cria o renderizador

    int tabuleiro[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}}; // Tabuleiro

    SDL_Rect matrizPosicoes[3][3] = { //Posições para imprimir a jogada
        {
            {75, 100, 71, 71},
            {240, 100, 71, 71},
            {415, 100, 71, 71}
        },


        {
            {75, 260, 71, 71},
            {240, 260, 71, 71},
            {415, 260, 71, 71}
        },

        {
            {75, 420, 71, 71},
            {240, 420, 71, 71},
            {415, 420, 71, 71}
        }
    };

    int jogador = 1;
    bool termina = false;
    SDL_Texture *tabTex = carregaImagem("assets/tabuleiro.bmp", renderizador);
    SDL_Texture *xTex = carregaImagem("assets/X.bmp", renderizador);
    SDL_Texture *oTex = carregaImagem("assets/O.bmp", renderizador);
    SDL_Texture *oneWins = carregaImagem("assets/1wins.bmp", renderizador);
    SDL_Texture *twoWins = carregaImagem("assets/2wins.bmp", renderizador);
    SDL_Texture *gameOver = carregaImagem("assets/gameOver.bmp", renderizador);

    imprimeMapa(renderizador, tabTex);

    while (!termina) {

        escolheJogada(tabuleiro, jogador);

        imprimeJogada(tabuleiro, renderizador, xTex, oTex, matrizPosicoes);

        termina = verificaFinal(tabuleiro, renderizador, oneWins, twoWins, gameOver);

        SDL_RenderPresent(renderizador);

        SDL_Delay(1000/60);

        if (termina == true){
            SDL_Delay(2000);
        }

    }

    SDL_DestroyWindow(janela);

    SDL_Quit();

    return 0;
}
