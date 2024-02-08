#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#define WIDTH 640
#define HEIGHT 830
#define BALL_SIZE 10

typedef struct Ball{
    float x;
    float y;
    float xspeed;
    float yspeed;
    int size;
}Ball;
    void initialize(void);
    void SDL_ExitWithError(const char* msg);
    void SDL_Destroy(SDL_Window* window, SDL_Renderer* renderer, const char* msg);
    void Update(float elapsed, SDL_Renderer* renderer, Ball ball);
    SDL_bool CoinFile(void);
    Ball makeBall(int size);
    void RenderBall(const Ball* ball, SDL_Renderer* renderer); 
    void updateBall(Ball* ball, float elapsed);

#endif