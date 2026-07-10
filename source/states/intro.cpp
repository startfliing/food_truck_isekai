// play intro images, allow for skip on key_hit(KEY_START)

//exit states: title
#include "intro.hpp"
#include "title.hpp"

#include "terminal.hpp"

GameState introState(){
    Terminal::log("intro state");

    while(!key_hit(KEY_ANY)){
        key_poll();
        VBlankIntrWait();
    }
    key_poll();
    
    // For now, loop back to itself
    // Later you can transition to other states like: mainMenuState, playState, etc.
    return (GameState)&titleState;
}