#pragma once 

// Headers
#include <stdbool.h>

// Definitions
#define MAX_DRIVER_LENGTH               32
#define MAX_BODY_LENGTH                 32
#define INITIAL_PRODUCTION_CAPACITY     32

// Structures
typedef struct {
    char* driver;
    char* body;
} Production;

typedef struct {
    Production* productions;
    int size;
    int capacity;
} Grammar;

// Functions
Grammar* grammar_create(const char* filePath);
void grammar_destroy(Grammar* grammar);