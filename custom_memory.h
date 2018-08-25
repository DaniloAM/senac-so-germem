//
//  custom_memory.h
//  memoryAlloc
//
//  Created by Danilo Mative on 24/08/2018.
//  Copyright © 2018 Danilo Mative. All rights reserved.
//

#ifndef custom_memory_h
#define custom_memory_h

#include <stdio.h>

void clear_heap(void);
void print_heap(void);
void libera(void* mem);
void * aloca(unsigned int quantity);

#endif /* custom_memory_h */
