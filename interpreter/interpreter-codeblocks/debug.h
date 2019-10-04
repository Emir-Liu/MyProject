#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif // DEBUG_H_INCLUDED
