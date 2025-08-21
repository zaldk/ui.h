/* vim: set ft=c: */
#include <stdio.h>

#define UI_CONTEXT_LENGTH 1024

typedef enum UI_LayoutType {
    UI_LAYOUT_ROW, // windows go in a row, from left to right
    UI_LAYOUT_COL, // windows go in a column, from top to bottom
} UI_LayoutType;

typedef struct UI_Layout {
    UI_LayoutType type;
    int* children;
    int children_length;
} UI_Layout;

typedef struct UI_Context {
    UI_Layout storage[UI_CONTEXT_LENGTH];
    UI_Layout root;
} UI_Context;

void ui_call_me(void) {
    printf("%ld\n", sizeof(UI_Context));
}
