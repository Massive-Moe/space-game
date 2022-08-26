#pragma once

#define SIZE(x)  (sizeof(x) / sizeof((x)[0]))

float Cycle(int min, int max, float value)
{
    if (value < min)
        return max;
    else if (value > max)
        return min;
    return value;
}