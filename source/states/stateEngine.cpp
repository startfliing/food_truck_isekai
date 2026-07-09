#include "pregame.hpp"
#include "terminal.hpp"
#include "save.hpp"

#include "image.h"

u16 initTerminal(){
    u16 dcnt = DCNT_BG1 | DCNT_BG0;
    u8 cbb = 0;
    u8 sbb = 16;
    REG_BG0CNT = BG_BUILD(cbb, sbb, 0, 0, 1, 0, 0);

    //load palette
    memcpy16(pal_bg_mem, imagePal, imagePalLen/2);

    //load tiles
    LZ77UnCompVram(imageTiles, tile_mem[cbb]);
    
    //load image
    memcpy16(&se_mem[sbb], imageMap, imageMapLen/2);

    REG_BG1CNT = Terminal::setCNT(1, sbb+1, cbb+1);

    return dcnt;
}

int main(){

    REG_DISPCNT = initTerminal() | DCNT_MODE0;

    // Initialize Interrupts
    irq_init(nullptr);
	irq_enable(II_VBLANK);

    load();

    // Initialize and run the state engine
    // Start with pregame state, then let each state return the next one
    GameState currentState = (GameState)pregameState;
    
    while(1){
        // Execute current state and get the next state
        // Each state decides what state to run next and returns it
        currentState = (GameState)currentState();

    }

    return 0;
}