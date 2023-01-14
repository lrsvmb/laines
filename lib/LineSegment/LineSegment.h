#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include <FastLED.h>
#include "Animation.h"

typedef struct LineSegment
{
    uint8_t id;
    CRGB color;
} LineSegment;

void ls_setColor(LineSegment *segment, CRGB color);
void ls_setColor(LineSegment *segment, int r, int g, int b);
CRGB ls_getColor(LineSegment *segment);
void ls_setId(LineSegment *segment, uint8_t id);
int ls_getId(LineSegment *segment);

#endif