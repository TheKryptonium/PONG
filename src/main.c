#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <SDL.h>
#include "functions.h"

int main(int argc, char** argv){
    
    srand((unsigned int)time(NULL));
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
        SDL_ExitWithError("Echec lors de l'initialisation de la SDL");

    window =SDL_CreateWindow("PONG", 
                             SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                             HEIGHT, WIDTH,SDL_WINDOW_SHOWN);
    if(window==NULL)
        SDL_ExitWithError("La fenetre n'a pas été initialisée");
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);

    if(renderer==NULL)
        SDL_ExitWithError("Le rendu renderer n'a pas été initialisée");
    
   

    Ball ball = makeBall(BALL_SIZE);
    



    
    SDL_bool program = SDL_TRUE;
    SDL_Event event;

    Uint32 lastTicks = SDL_GetTicks(); 

    while(program){ 
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                program = SDL_FALSE;
                break;
            }
               
        }

        Uint32 current = SDL_GetTicks(); 
        Uint32 diff = current - lastTicks;
        float elapsed = diff/10.000f;
        Update(elapsed,renderer, ball);
        lastTicks = current;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}