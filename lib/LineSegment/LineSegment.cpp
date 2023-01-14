#include "LineSegment.h"

void ls_setColor(LineSegment *segment, CRGB color)
{
    segment->color = color;
}

void ls_setColor(LineSegment *segment, int r, int g, int b)
{
    segment->color = CRGB(r, g, b);
}

CRGB ls_getColor(LineSegment *segment)
{
    return segment->color;
}

void ls_setId(LineSegment *segment, int id)
{
    segment->id = id;
}

int ls_getId(LineSegment *segment)
{
    return segment->id;
}