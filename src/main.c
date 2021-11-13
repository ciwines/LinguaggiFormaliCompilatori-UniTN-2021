#include <lfc/grammar.h>
#include <stdio.h>

int main() {
    Grammar* test = grammar_create("test/input.txt");

    for (int i = 0; i < test->size; i++) {
        printf("drivrer: %s | body: %s\n", test->productions[i].driver, test->productions[i].body);
    }

    grammar_destroy(test);

    return 0;
}