# Word Reversal using Stack Data Structure

> A web application combining **Minimalism** and **Glassmorphism** styles, powered by a **C core** compiled to WebAssembly for stack-based word reversal.

---

## 📋 Project Overview

This project implements string reversal using the **Stack** data structure based on the **LIFO (Last-In, First-Out)** principle:
- The core stack operations (`push`, `pop`, `isEmpty`, `isFull`) and reversal logic are written in **C**.
- The C logic runs natively in the web browser through an embedded **WebAssembly** engine (with zero external dependencies).
- The web interface features a **minimalist, glassmorphism design** with an interactive visual stack chamber and a live 4-step algorithm flow.

---

## ⚙️ Algorithm Flow

Beside the I/O fields, the application displays and highlights the 4-step algorithm flow in real time:

```
[User Input Word]
       │
       ▼
┌────────────────────────────────────────────────────────┐
│ 1. Word input entered by the user                      │
└────────────────────────────────────────────────────────┘
       │
       ▼
┌────────────────────────────────────────────────────────┐
│ 2. Input word's characters are pushed one by one into  │
│    the stack (top increments: -1 -> 0 -> 1 ... -> n-1) │
└────────────────────────────────────────────────────────┘
       │
       ▼
┌────────────────────────────────────────────────────────┐
│ 3. The elements are popped one by one until the stack  │
│    is empty (underflow condition: isEmpty() == true)   │
└────────────────────────────────────────────────────────┘
       │
       ▼
┌────────────────────────────────────────────────────────┐
│ 4. Reversed string is displayed                        │
│    (LIFO property naturally inverts character order)   │
└────────────────────────────────────────────────────────┘
```

---

## 📁 Minimal File Structure (Designed for Project Submission)

To keep submission and deployment as simple as possible, the project contains only essential files:

```
d:/College/projekt/
├── index.html        # Complete website: UI, Glassmorphic CSS, visualizer & embedded C WASM engine
├── stack_reverse.c   # Standalone C program implementing Stack & word reversal CLI
├── Makefile          # One-command build and test automation
└── README.md         # Project documentation and evaluation guide
```

---

## 🚀 How to Run & Deploy

### 1. Direct Web Deployment (Zero Setup / Static Hosting)
- **Local:** Simply double-click `index.html` to open it in any web browser (Chrome, Edge, Firefox, Safari).
- **GitHub Pages:** Push this repository to GitHub and enable **Settings > Pages > Deploy from branch (main / root)**.
- **Vercel / Netlify:** Drag-and-drop the project folder or import from GitHub. `index.html` is 100% self-contained with no external CDN or server dependencies.

### 2. Standalone C Terminal Program
To compile and test the C program directly in the terminal:

```bash
# Using Makefile
make test

# Or manual compilation with GCC:
gcc -Wall -Wextra -O2 -std=c99 -o stack_reverse stack_reverse.c
./stack_reverse "ALGORITHM"
```

**Interactive C CLI Mode:**
```bash
./stack_reverse
Enter a word to reverse: DATASTRUCTURES
```

---

## 💻 C Implementation Highlights (`stack_reverse.c`)

```c
#define MAX_SIZE 1024

typedef struct {
    int top;
    int capacity;
    char items[MAX_SIZE];
} Stack;

// Initialize stack: top = -1 denotes empty state
void initStack(Stack *s) {
    s->top = -1;
    s->capacity = MAX_SIZE;
}

// Push element: increments top after overflow check
bool push(Stack *s, char element) {
    if (isFull(s)) return false;
    s->items[++(s->top)] = element;
    return true;
}

// Pop element: returns character and decrements top
// Returns '\0' on Stack Underflow
char pop(Stack *s) {
    if (isEmpty(s)) return '\0'; // Underflow
    return s->items[(s->top)--];
}

// Word reversal logic
char* reverseWord(const char *input, char *output) {
    Stack stack;
    initStack(&stack);
    int len = (int)strlen(input);

    // Step 2: Push one by one
    for (int i = 0; i < len; i++) {
        push(&stack, input[i]);
    }

    // Step 3: Pop one by one until stack is empty
    int j = 0;
    while (!isEmpty(&stack)) {
        output[j++] = pop(&stack);
    }
    output[j] = '\0';
    return output; // Step 4: Display reversed string
}
```

---

## 🎨 UI & UX Design Features

- **Glassmorphism Aesthetic:**
  - Multi-layer frosted panels using `backdrop-filter: blur(20px) saturate(180%)`.
  - Ambient radial gradients producing subtle colorful glow on dark navy canvas.
  - Translucent 1px border highlights (`rgba(255, 255, 255, 0.12)`) and inner rim shadows.
- **Minimalism:**
  - Clear visual hierarchy with ample white/negative space.
  - Distraction-free typography with high-contrast text and crisp monospaced counters.
- **Interactive Stack Chamber:**
  - Real-time animated vertical glass vessel showing stack elements entering from top.
  - Dynamic `TOP` pointer tracking `top = -1` (Underflow) to `top = n - 1`.
  - Memory address simulation tags and underflow status flags.
- **Side-by-Side Algorithm Stepper:**
  - Synchronous active glow highlighting each of the 4 steps as execution proceeds.
- **Interactive Code Inspector:**
  - In-browser syntax-highlighted C code viewer.
- **Palindrome Detector:**
  - Automatically identifies whether the input string is a palindrome (e.g., `RADAR`, `KAYAK`).

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ | $N$ push operations + $N$ pop operations where $N$ is the length of the string |
| **Auxiliary Space** | $\mathcal{O}(N)$ | Stack array storing $N$ characters in memory |
| **Stack Overflow** | $\mathcal{O}(1)$ check | `top >= capacity - 1` |
| **Stack Underflow** | $\mathcal{O}(1)$ check | `top < 0` (stops popping when empty) |
