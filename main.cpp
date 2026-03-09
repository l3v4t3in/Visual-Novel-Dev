#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 1920, HEIGHT = 1080;

class Scene{
private:
  SDL_Event event;
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool running = false;
  int ScreenWith = 0;
  int ScreenHeight = 0;
  int i = 0;
  int Color[3][3] = {
    {255,0,0},
    {0,255,0},
    {0,0,255}
  };
public:
  Scene(){
    window = SDL_CreateWindow("0",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH, HEIGHT,SDL_WINDOW_FULLSCREEN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    running = true;
  }
  void run(){
      while (running) {
          imput();
          update();
          rendor();
      }
   }
  void imput(){
    while(SDL_PollEvent(&event)){
      switch (event.type)
      {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_MOUSEBUTTONDOWN:
        if(event.button.button == SDL_BUTTON_LEFT){
          if(i == 2){
            i = 0;}
          else{ 
            i+=1;}
        }
        break;
      default:  
        break;
      }

    }
  }
  void update(){}
  void rendor(){
    SDL_SetRenderDrawColor(renderer, Color[i][0], Color[i][1], Color[i][2], 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

  }
};

int main() {
  
  Scene scene;
  scene.run();
  return 0;
}