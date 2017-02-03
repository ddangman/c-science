/*
 * union is a special data type that stores different data types in the same memory location
 * you can define union with many members, but only one member can contain value at any given time
 * union is only given memory == to the largest member,
 * struct allocates sum of all members + compiler dependent buffering (ie round up to next % 8 byte)
 * union provide an efficient way of using the same memory location for multi-purpose
 */


#include <stdio.h>
#include <string.h>
// stdlib.h is needed to declare EXIT_SUCCESS
#include <stdlib.h>

typedef enum {
    CHAR, SHORT, INTEGER, FLOAT, DOUBLE, STRING
} TYPE;

typedef union {
    char Character;
    short Short;
    int Integer;
    float Float;
    double Double;
    char String[100];
} Value;

typedef struct {
    TYPE type;
    Value value;
} Variant;

// forward declaration
// function prototype is a declaration that can happen anywhere
// must be located after struct is declared/defined or compiler error
void Method(Variant v);
void changeStructElement(Variant *pointer);
//void PassByValue(struct arg);
//void PassByReference(struct &arg);
// PassByValue copies object that is deleted once function if popped off stack,
// actual object remains the same
//PassByReference is faster since there is no copy. All modifications apply to original

int main(int argc, char** argv) {
    Variant v1;
    v1.type = DOUBLE;
    v1.value.Double = 100.1;

    // initializing struct like an array
    Variant v2 = {
        CHAR,
        'A'
    };
    Method(v2);

    Method(v1);
    // can pass address or pointer since method parameter is pointer
    changeStructElement(&v1);
    Method(v1);
    return (EXIT_SUCCESS);
}

void Method(Variant v) {
    if (v.type == CHAR)
        printf("%c", v.value.Character);
    else if (v.type == SHORT)
        printf("%d", v.value.Short);
    else if (v.type == INTEGER)
        printf("%d", v.value.Integer);
    else if (v.type == FLOAT)
        printf("%f", v.value.Float);
    else if (v.type == DOUBLE)
        // double requires %lf
        printf("%lf", v.value.Double);
    else if (v.type == STRING)
        printf("%s", v.value.String);
    printf("\n");
}

/*
struct and union are pass by values if used in functions
to change values, a pointer must be used with brackets to explicitly ensure proper precedence
&(*pointer).element
or
pointer->element
*/

void changeStructElement(Variant *pointer) {
  printf("Enter new type integer\n");
  // alternative format
  // scanf("%d", &pointer->type);
  scanf("%d", &(*pointer).type);
  printf("Enter new value\n");
  fflush(stdout);
  // alternative format
  // switch (pointer->type) {
  switch ((*pointer).type) {
    case 0:
      // catch newline char
      getc(stdin);
      scanf("%c", &(*pointer).value.Character);
      break;
    case 1:
      scanf("%d", &(*pointer).value.Short);
      break;
    case 2:
      scanf("%d", &(*pointer).value.Integer);
      break;
    case 3:
      scanf("%f", &(*pointer).value.Float);
      break;
    case 4:
      scanf("%f", &(*pointer).value.Double);
      break;
    case 5:
      scanf("%s", &(*pointer).value.String);
      break;
  }
}
