// functions.hpp
//

#ifndef FUNCTIONS_functions_h
#define FUNCTIONS_functions_h
#ifdef _WIN32
    typedef unsigned char uint8_t;
#endif
int gen_int(int min, int max);
void swap_int(int* a, int* b);
bool gen_arraySet(int* array, int arraySize);
void term_getDim(uint8_t* width, uint8_t* height);
void term_clear();
#endif
