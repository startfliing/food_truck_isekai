#include "save.hpp"
#include "tonc.h"

void sramCpy(u8* src, u8* dst){
    for(size_t i = 0; i < sizeof(saveData); i++){
        dst[i] = src[i];
    }
}

void save(saveData* data, int saveSlot){
    saveData* memStart = (saveData*)sram_mem;

    u8* cpySrc = (u8*)data;
    u8* cpyDst = &sram_mem[sizeof(saveData)*saveSlot];

    sramCpy(cpySrc, cpyDst);
}

saveData load(int saveSlot){
    saveData ret;

    //saveData* memStart = &sram_mem[sizeof(saveData)*saveSlot];

    u8* cpySrc = &sram_mem[sizeof(saveData)*saveSlot];
    u8* cpyDst = (u8*)&ret;

    sramCpy(cpySrc, cpyDst);
    return ret;
}