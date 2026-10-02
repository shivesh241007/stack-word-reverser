/**
 * ============================================================================
 * Project: Word Reversal using Stack Data Structure
 * Language: C (C99/C11 Standard)
 *
 * Algorithm Steps:
 *  1. Word input entered by the user
 *  2. Input word's characters are pushed one by one into the stack
 *  3. The elements are popped one by one until the stack is empty (underflow)
 *  4. Reversed string is displayed
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1024

// Stack definition using an array
typedef struct {
    int top;
    int capacity;
    char items[MAX_SIZE];
} Stack;

// Initialize stack with empty state (top = -1)
void initStack(Stack *s) {
    s->top = -1;
    s->capacity = MAX_SIZE;
}

// Check if the stack is full (Overflow condition)
bool isFull(const Stack *s) {
    return s->top >= s->capacity - 1;
}

// Check if the stack is empty (Underflow condition)
bool isEmpty(const Stack *s) {
    return s->top < 0;
}

// Push an element onto the stack
// Returns true on success, false on Stack Overflow
bool push(Stack *s, char element) {
    if (isFull(s)) {
        printf("[ERROR] Stack Overflow: Cannot push '%c'\n", element);
        return false;
    }
    s->items[++(s->top)] = element;
    return true;
}

// Pop an element from the stack
// Returns the popped character, or '\0' on Stack Underflow
char pop(Stack *s) {
    if (isEmpty(s)) {
        // Stack Underflow condition
        return '\0';
    }
    return s->items[(s->top)--];
}

// Peek top element without popping
char peek(const Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Get current size of stack
int getStackSize(const Stack *s) {
    return s->top + 1;
}

/**
 * Reverses an input word using Stack operations:
 * - Step 1: Takes user input string
 * - Step 2: Pushes each character into stack
 * - Step 3: Pops each character until stack underflow occurs (isEmpty becomes true)
 * - Step 4: Stores and returns reversed string in `output` buffer
 */
char* reverseWord(const char *input, char *output) {
    if (input == NULL || output == NULL) {
        return NULL;
    }

    Stack stack;
    initStack(&stack);

    int length = (int)strlen(input);

    printf("--- [ALGORITHM FLOW START] ---\n");
    printf("Step 1: Received word input: \"%s\" (Length: %d)\n", input, length);

    // Step 2: Push characters one by one into the stack
    printf("\nStep 2: Pushing characters one by one into the stack...\n");
    for (int i = 0; i < length; i++) {
        push(&stack, input[i]);
        printf("  Pushed: '%c' | Stack Top: %d | Current Stack: [", input[i], stack.top);
        for (int k = 0; k <= stack.top; k++) {
            printf("%c%s", stack.items[k], (k < stack.top ? ", " : ""));
        }
        printf("]\n");
    }

    // Step 3: Pop elements one by one until stack is empty
    printf("\nStep 3: Popping characters one by one until stack underflow...\n");
    int outIdx = 0;
    while (!isEmpty(&stack)) {
        char ch = pop(&stack);
        output[outIdx++] = ch;
        printf("  Popped: '%c' | Next Stack Top: %d | Underflow Reached? %s\n",
               ch, stack.top, isEmpty(&stack) ? "YES (Stack Empty)" : "NO");
    }
    output[outIdx] = '\0'; // Null-terminate string

    // Step 4: Reversed string is ready
    printf("\nStep 4: Reversed string constructed: \"%s\"\n", output);
    printf("--- [ALGORITHM FLOW COMPLETE] ---\n\n");

    return output;
}

// Main function for standalone C CLI execution / testing
int main(int argc, char *argv[]) {
    char input[MAX_SIZE];
    char output[MAX_SIZE];

    printf("====================================================\n");
    printf("     WORD REVERSAL USING STACK DATA STRUCTURE (C)    \n");
    printf("====================================================\n");

    if (argc > 1) {
        // Use command line argument if provided
        strncpy(input, argv[1], MAX_SIZE - 1);
        input[MAX_SIZE - 1] = '\0';
    } else {
        // Interactive prompt
        printf("Enter a word to reverse: ");
        if (scanf("%1023s", input) != 1) {
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }
    }

    reverseWord(input, output);

    printf("Input Word    : %s\n", input);
    printf("Reversed Word : %s\n", output);

    return 0;
}
