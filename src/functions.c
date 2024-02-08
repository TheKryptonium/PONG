#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#include <SDL.h>
#include "functions.h"

void SDL_ExitWithError(const char* msg){
    SDL_Log("%s\nErreur : %s", msg, SDL_GetError());
    SDL_Quit();
    exit (EXIT_FAILURE);
}

void SDL_Destroy(SDL_Window* window, SDL_Renderer* renderer, const char* msg){
    SDL_ExitWithError(msg);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void Update(float elapsed, SDL_Renderer* renderer, Ball ball){
    if(SDL_SetRenderDrawColor(renderer,0,0,25,1)!=0)
        SDL_ExitWithError("Impossible de changer la couleur de la fenêtre");

    SDL_RenderClear(renderer);
    

    updateBall(&ball, elapsed);
    RenderBall(&ball,renderer);

    
    SDL_RenderPresent(renderer);
}

SDL_bool CoinFlip(void){
    return rand()%2==1 ? SDL_TRUE:SDL_FALSE;
}
    

Ball makeBall(int size){
    int SPEED = 120;
    Ball ball={
        .x = (HEIGHT - size)/2,
        .y = (WIDTH - size)/2,
        .size = size,
        .xspeed = SPEED*(CoinFlip()?1:-1),
        .yspeed = SPEED*(CoinFlip()?1:-1),
    };
    return ball;
}

void RenderBall(const Ball* ball, SDL_Renderer* renderer){
    int size = ball->size;
    int halfSize = size/2;
    SDL_Rect rect={
        .x=ball-> x-halfSize,
        .y=ball-> y-halfSize,
        .h=size,
        .w=size,
    };

    if(SDL_SetRenderDrawColor(renderer, 255,255,255,1)!=0)
        SDL_ExitWithError("Impossible de changer la couleur de Ball");

    if(SDL_RenderFillRect(renderer, &rect)!=0)
        SDL_ExitWithError("Impossible de remplir le rectangle");

}

void updateBall(Ball* ball, float elapsed){
    ball->x += ball->xspeed*elapsed;
    ball->y += ball->yspeed*elapsed;

    if(ball->x < 0)
        ball->xspeed = fabs(ball->xspeed);

    if(ball->x > HEIGHT-BALL_SIZE)
        ball->xspeed = -fabs(ball->xspeed);

    if(ball->y<0)
        ball->yspeed = fabs(ball->yspeed); 
    
    if(ball->y > WIDTH-BALL_SIZE)
        ball->yspeed = -fabs(ball->yspeed);
    

}
