#ifndef LINE_H
#define LINE_H

#define LINE_SEGMENT_COUNT 10

#include <FastLED.h>
#include "Animation.h"
#include "LineSegment.h"

typedef struct Line
{
    LineSegment segments[LINE_SEGMENT_COUNT];
    Animation animation;
} Line;

#endif