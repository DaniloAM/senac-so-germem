//
//  custom_memory.c
//  memoryAlloc
//
//  Created by Danilo Mative on 24/08/2018.
//  Copyright © 2018 Danilo Mative. All rights reserved.
//

#include "custom_memory.h"

#define SIZE 1024
#define CLEAR 0x00000000

uint8_t heap[SIZE];


void clear_heap() {
    
    int x = 0;
    
    while(x < SIZE) {
        
        heap[x] = CLEAR;
        x++;
    }
    
}

void print_heap() {
    
    int x = 0;
    
    printf("[");
    
    while(x < SIZE) {
        
        
        printf(" %02X", heap[x]);
        
        x++;
    }
    
    printf("]\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

void libera(void* mem) {
    
    if(mem == NULL) {
        return;
    }
    
    uint8_t *change = (uint8_t *)mem - 1;
    unsigned int value = *change;
    
    int qt = value, x = 0;
    
    while(x < qt) {
        
        *change = CLEAR;
        change = change + 1;
        x++;
    }
    
    change = NULL;
    mem = NULL;
    
}

void * aloca(unsigned int quantity) {
    
    if(quantity > SIZE || quantity == 0) {
        return NULL;
    }
    
    int pos = 0;
    int count = 0;
    
    while(pos + quantity < SIZE) {
        
        uint8_t val = heap[pos];
        
        if(val == '\0') {
            count++;
        }
        else {
            pos = pos + heap[pos];
            count = 0;
        }
        
        
        pos++;
        
        
        if(count >= quantity) {
            
            pos -= quantity;
            heap[pos] = (uint8_t)quantity;
            break;
        }
        
    }
    
    if(pos + quantity >= SIZE) {
        return NULL;
    }
    
    return &heap[pos+1];
}
