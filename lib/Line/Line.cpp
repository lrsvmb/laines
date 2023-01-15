#include "Line.h"

void line_init(Line *line)
{
    line->animation = Animation::NONE;
    for (uint8_t i = 0; i < LINE_SEGMENT_COUNT; i++)
    {
        ls_setId(&line->segments[i], i);
        ls_setColor(&line->segments[i], CRGB(0, 0, 0));
    }
}

void line_initFromSegments(Line *line, LineSegment *segments)
{
    line->animation = Animation::NONE;
    line_setSegments(line, segments);
}

// Logic
void line_update(Line *line)
{
}

// Animation

void line_setAnimation(Line *line, Animation animation)
{
    line->animation = animation;
}

Animation line_getAnimation(Line *line)
{
    return line->animation;
}

// Segments

LineSegment *line_getSegments(Line *line)
{
    return line->segments;
}

void line_setSegments(Line *line, LineSegment *segments)
{
    for (uint8_t i = 0; i < LINE_SEGMENT_COUNT; i++)
    {
        line->segments[i] = segments[i];
    }
}

void line_setSegment(Line *line, uint8_t index, LineSegment *segment)
{
    line_setSegment(line, index, segment);
}

LineSegment *line_getSegment(Line *line, uint8_t index)
{
    return &line->segments[index];
}

LineSegment *line_getSegmentById(Line *line, uint8_t id)
{
    for (uint8_t i = 0; i < LINE_SEGMENT_COUNT; i++)
    {
        if (line->segments[i].id == id)
        {
            return line_getSegment(line, i);
        }
    }
    return NULL;
}

LineSegment *line_getSegmentByColor(Line *line, CRGB color)
{
    for (uint8_t i = 0; i < LINE_SEGMENT_COUNT; i++)
    {
        if (line->segments[i].color == color)
        {
            return line_getSegment(line, i);
        }
    }
    return NULL;
}

LineSegment *line_getFirstSegmentInArray(Line *line)
{
    return &line->segments[0];
}

LineSegment *line_getLastSegmentInArray(Line *line)
{
    return &line->segments[LINE_SEGMENT_COUNT - 1];
}

LineSegment *line_getFirstSegmentById(Line *line)
{
    // return segment with smallest id
    uint8_t smallestId = LINE_SEGMENT_COUNT + 1;
    LineSegment *smallestSegment = NULL;
    for (uint8_t i = 0; i < LINE_SEGMENT_COUNT; i++)
    {
        if (line->segments[i].id < smallestId)
        {
            smallestId = line->segments[i].id;
            smallestSegment = &line->segments[i];
        }
    }
    return smallestSegment;
}

LineSegment *line_getLastSegmentById(Line *line)
{
    // return segment with largest id
    int largestId = -1;
    LineSegment *largestSegment = NULL;
    for (uint8_t i = 0; i < LINE_SEGMENT_COUNT; i++)
    {
        if (line->segments[i].id > largestId)
        {
            largestId = line->segments[i].id;
            largestSegment = &line->segments[i];
        }
    }
    return largestSegment;
}

// Color

CRGB line_getAverageColor(Line *line)
{
    // get the average color in all segments
    uint16_t r = 0;
    uint16_t g = 0;
    uint16_t b = 0;
    for (uint8_t i = 0; i < LINE_SEGMENT_COUNT; i++)
    {
        LineSegment *segment = &line->segments[i];
        r += ls_getColor(segment).r;
        g += ls_getColor(segment).g;
        b += ls_getColor(segment).b;
    }
    r /= LINE_SEGMENT_COUNT;
    g /= LINE_SEGMENT_COUNT;
    b /= LINE_SEGMENT_COUNT;
    return CRGB(r, g, b);
}

void line_setAverageColor(Line *line, CRGB color)
{
    // TODO set the average color in all segments
}

void line_setColor(Line *line, CRGB color)
{
    for (uint8_t i = 0; i < LINE_SEGMENT_COUNT; i++)
    {
        ls_setColor(&line->segments[i], color);
    }
}

void line_setColor(Line *line, int r, int g, int b)
{
    line_setColor(line, CRGB(r, g, b));
}

// Brightness

uint8_t line_getBrightness(Line *line)
{
    return line->brightness;
}

void line_setBrightness(Line *line, uint8_t brightness)
{
    FastLED.setBrightness(brightness);
    line->brightness = brightness;
}