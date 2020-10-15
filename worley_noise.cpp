/*https://en.wikipedia.org/wiki/Worley_noise
  Serkan Can Caglayan 10/9/2020
*/
#include "funcs.h"
int main(int argc, char* argv[]) {
	if (!SDL_Init(SDL_INIT_VIDEO)){
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Event event;
		SDL_bool done = SDL_FALSE;
		vector<SDL_Point> random_points;
		for (int i = 0; i < number_of_random_points; i++) {
			int x = rand() % WindowWidth;
			int y = rand() % WindowHeight;
			SDL_Point p = { x , y };
			random_points.push_back(p);
		}
		if (!SDL_CreateWindowAndRenderer(WindowWidth, WindowHeight, 0, &window, &renderer)){
			for (int i = 0; i < WindowWidth; i++) {
				for (int j = 0; j < WindowHeight; j++) {
					int color = worley_noise(random_points, i, j, 2) % 256;
					SDL_SetRenderDrawColor(renderer, color, color, color, SDL_ALPHA_OPAQUE);
					SDL_RenderDrawPoint(renderer, i, j);
				}
			}
			SDL_RenderPresent(renderer);
			while (!done){
				SDL_PollEvent(&event);
				if (event.type == SDL_QUIT) {
					done = SDL_TRUE;
				}
			}
		}
		else{
			std::cerr << "Failed to create window or renderer" << std::endl;
			exit(EXIT_FAILURE);
		}
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}
	else{
		std::cerr << "Failed to initialize SDL2" << std::endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}