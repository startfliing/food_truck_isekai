#ifndef __SAVE__
#define __SAVE__

#include "tonc.h"

struct saveData{
    u16 score;
} __attribute__((packed));

void save(saveData* data, int saveSlot);

saveData load(int saveSlot);

#endif