#include <stdio.h>

// Adaptee: Legacy printer
void legacyPrint(const char* text) {
    printf("Legacy Printer: %s\n", text);
}

// Target interface
typedef struct {
    void (*print)(const char*);
} ModernPrinter;

// Adapter
void adapterPrint(const char* text) {
    printf("Adapter translating...\n");
    legacyPrint(text);  // Call adaptee
}

int main() {
    ModernPrinter printer;
    printer.print = adapterPrint;

    printer.print("Hello via Adapter Pattern!");
    return 0;
}
