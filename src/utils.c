#include "raylib.h"

float dynamic_roundness(Rectangle rectangle,float roundness) {
    float smaller_size = (rectangle.height >= rectangle.width) ? rectangle.width : rectangle.height;
    float ret_val = (roundness * 2) / smaller_size;
    if (ret_val > 1.0f) return 1.0f;
    if (ret_val < 0.0f) return 0.0f;
    return ret_val;
}