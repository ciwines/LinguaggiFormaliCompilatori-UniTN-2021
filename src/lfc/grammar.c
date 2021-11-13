// Headers
#include <lfc/grammar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementation
// Generates a new grammar starting from an input file
Grammar* grammar_create(const char* filePath) {
    FILE* inputFile = fopen(filePath, "r");
    if (!inputFile) {
        return NULL;
    }

    Grammar* grammar = (Grammar*) malloc(sizeof(Grammar));
    if (!grammar) {
        return NULL;
    }

    grammar->productions = (Production*) malloc(sizeof(Production) * INITIAL_PRODUCTION_CAPACITY);
    if (!grammar) {
        free(grammar);
        return NULL;
    }

    grammar->capacity = INITIAL_PRODUCTION_CAPACITY;
    grammar->size = 0;

    char driver[MAX_DRIVER_LENGTH] = {0};    
    char body[MAX_BODY_LENGTH] = {0};

    while (fscanf(inputFile, "%s -> %s", driver, body) != EOF) {
        Production tmp = {
            .driver = (char*) malloc(strlen(driver)),
            .body = (char*) malloc(strlen(body))
        };

        strncpy(tmp.driver, driver, strlen(driver));
        strncpy(tmp.body, body, strlen(body));

        grammar->size += 1;
        if (grammar->size > grammar->capacity) {
            int newCapacity = grammar->capacity * 2;
            Production* newProductions = (Production*) realloc(grammar->productions, newCapacity * sizeof(Production));

            if (!newProductions) {
                grammar_destroy(grammar);
                return NULL;
            }

            grammar->productions = newProductions;
            grammar->capacity = newCapacity;
        }

        grammar->productions[grammar->size - 1] = tmp;
    }

    fclose(inputFile);

    return grammar;
}

void grammar_destroy(Grammar* grammar) {
    if (!grammar) {
        return;
    }

    if (!grammar->productions) {
        free(grammar);
        return;
    }

    for (int i = 0; i < grammar->size; i++) {
        free(grammar->productions[i].driver);
        free(grammar->productions[i].body);
    }

    free(grammar->productions);
}