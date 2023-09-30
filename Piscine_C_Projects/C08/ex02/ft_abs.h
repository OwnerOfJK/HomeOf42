#ifndef FT_ABS_HEADER
#define FT_ABS_HEADER


//The following solution uses a macro which makes the c preprocessor essentially replace ABS in the with the following as oppose to making a function call. This is more performent.
#define ABS(x) ((x) < 0 ? -(x) : (x))

//The following solution uses a function and is less performent as the program needs to call an additional function.
/*int ABS(Value) {
    if (Value < 0)
    {
        Value = -Value;            
    }
    return (Value);
}*/

#endif