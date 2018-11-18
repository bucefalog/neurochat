#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

int initSharedMemory();
void smWriteId(int id);
void closeSharedMemory();

#endif // SHAREDMEMORY_H