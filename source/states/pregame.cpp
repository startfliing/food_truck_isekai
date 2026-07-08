#include "tonc.h"

#include "terminal.hpp"
#include "ingame.hpp"

// Pregame state implementation
// This state handles pre-game setup and returns the next state to run
GameState pregameState(){
    Terminal::log("pregame");

    while(!key_hit(KEY_ANY)){
        key_poll();
        VBlankIntrWait();
    }
    key_poll();
    
    // For now, loop back to itself
    // Later you can transition to other states like: mainMenuState, playState, etc.
    return (GameState)&ingameState;
}