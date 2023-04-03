#include <SDL.h>
#include <list>
#include "Hero.h"
#include "class/ClassImpl.h"

using namespace He_ARC::rpg;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Goloviatinski Fil Rouge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600 ,0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    
    bool running = true;
    while(running) {
        //handle events
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
            {
                running = false;
                break;
            }
        }

        Warrior *war1 = new Warrior;
        Rogue *rog1 = new Rogue;
        Wizard *wzd1 = new Wizard;
        Necromancer *ncm1 = new Necromancer;
        list<Hero*> party;
        party.push_back(war1);
        party.push_back(rog1);
        party.push_back(wzd1);
        party.push_back(ncm1);

        for(Hero *member : party) {
            cout << *member;
        }

        war1->interact(*wzd1);
        wzd1->interact(*ncm1);
        rog1->interact(*wzd1);

        wzd1->castSpell();
        ncm1->castSpell();
        ncm1->raiseUndeads();

        for(Hero *member : party) {
            delete member;
        }

        //clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        // draw a point
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, 100, 100);

        // flip buffers and display what we've drawn
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}