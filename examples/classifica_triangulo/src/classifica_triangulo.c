#include <stdio.h>
#include <stdlib.h>

char* classifica_triangulo(int a, int b, int c) {
    static const char *EQ = "equilatero";
    static const char *IS = "isosceles";
    static const char *ES = "escaleno";
    static const char *ER = "erro";

    // Sides must be positive
    if (a <= 0 || b <= 0 || c <= 0) return (char*)ER;

    // Sort sides: x <= y <= z
    int x = a, y = b, z = c, t;
    if (x > y) { t = x; x = y; y = t; }
    if (y > z) { t = y; y = z; z = t; }
    if (x > y) { t = x; x = y; y = t; }

    // Triangle inequality with overflow-safe sum
    long long sum = (long long)x + (long long)y;
    if (sum <= z) return (char*)ER;

    if (x == y && y == z) return (char*)EQ;
    if (x == y || x == z || y == z) return (char*)IS;
    return (char*)ES;
}

