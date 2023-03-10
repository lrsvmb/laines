#ifndef LINE_H
#define LINE_H

#define LINE_SEGMENT_COUNT 10
#define LED_COUNT 300

#include <FastLED.h>
#include "Animation.h"
#include "LineSegment.h"

// ---------- Types ----------
typedef struct Line
{
    LineSegment segments[LINE_SEGMENT_COUNT];
    Animation animation;
    uint8_t brightness;
} Line;

Line line;

// ---------- Functions ----------
void line_init(Line *line);
void line_initFromSegments(Line *line, LineSegment *segments);
// Logic
void line_update(Line *line);
// Animation
void line_setAnimation(Line *line, Animation animation);
Animation line_getAnimation(Line *line);
// Segments
LineSegment *line_getSegments(Line *line);
void line_setSegments(Line *line, LineSegment *segments);
void line_setSegment(Line *line, uint8_t index, LineSegment *segment);
LineSegment *line_getSegment(Line *line, uint8_t index);
LineSegment *line_getSegmentById(Line *line, uint8_t id);
LineSegment *line_getSegmentByColor(Line *line, CRGB color);
// Color
CRGB line_getAverageColor(Line *line);
void line_setAverageColor(Line *line, CRGB color);
void line_setColor(Line *line, CRGB color);
void line_setColor(Line *line, int r, int g, int b);
// Brightness
uint8_t line_getBrightness(Line *line);
void line_setBrightness(Line *line, uint8_t brightness);

#endif