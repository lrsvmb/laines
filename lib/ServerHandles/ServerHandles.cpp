#include "ServerHandles.h"
#include "LineServer.h"
#include "Line.h"
#include "LineSegment.h"
#include <iostream>

// ------------------ Color ------------------ //

CRGB *hex_to_crgb(const char *hex)
{
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    return new CRGB(r, g, b);
}

void sh_setColor()
{
    if (server.hasArg("id"))
    {
        if (server.hasArg("color"))
        {
            // convert hex color arg to CRGB
            CRGB *color = hex_to_crgb(server.arg("color").c_str());
            // get id
            int id = server.arg("id").toInt();

            // get segment
            LineSegment *segment = line_getSegment(&line, id);
            // set color
            ls_setColor(segment, *color);
            server.send(200, "text/plain", "OK");
        }
        else
        {
            server.send(400, "text/plain", "Bad Request");
        }
    }
    else if (server.hasArg("method"))
    {
        if (server.arg("method").equals("average"))
        {
            // convert hex color arg to CRGB
            CRGB *color = hex_to_crgb(server.arg("color").c_str());
            // set color
            line_setAverageColor(&line, *color);
            server.send(200, "text/plain", "OK");
        }
        else if (server.arg("method").equals("all"))
        {
            CRGB *color = hex_to_crgb(server.arg("color").c_str());
            // set color
            line_setColor(&line, *color);
            server.send(200, "text/plain", "OK");
        }
        else
        {
            server.send(400, "text/plain", "Bad Request");
        }
    }
    else
    {
        server.send(400, "text/plain", "Bad Request");
    }
}

void sh_getColor()
{
    // return average line color in hex
    CRGB color = line_getAverageColor(&line);
    server.send(200, "text/plain", String(color.r, HEX) + String(color.g, HEX) + String(color.b, HEX));
}

void sh_color()
{
    if (server.method() == HTTP_GET)
    {
        sh_getColor();
    }
    else if (server.method() == HTTP_POST)
    {
        sh_setColor();
    }
    else
    {
        server.send(405, "text/plain", "Method Not Allowed");
    }
}

// ------------------ Animation ------------------ //

void sh_setAnimation()
{
    if (server.hasArg("animation"))
    {
        // get animation
        Animation animation = (Animation)server.arg("animation").toInt();
        // set animation
        line_setAnimation(&line, animation);
        server.send(200, "text/plain", "OK");
    }
    else
    {
        server.send(400, "text/plain", "Bad Request");
    }
}

void sh_getAnimation()
{
    // get animation
    Animation animation = line_getAnimation(&line);
    server.send(200, "text/plain", String(animation).c_str());
}

void sh_animation()
{
    if (server.method() == HTTP_GET)
    {
        sh_getAnimation();
    }
    else if (server.method() == HTTP_POST)
    {
        sh_setAnimation();
    }
    else
    {
        server.send(405, "text/plain", "Method Not Allowed");
    }
}

// ------------------ Brightness ------------------ //

void sh_setBrightness()
{
    if (server.hasArg("brightness"))
    {
        // get brightness
        int brightness = server.arg("brightness").toInt();
        // set brightness
        line_setBrightness(&line, brightness);
        server.send(200, "text/plain", "OK");
    }
    else
    {
        server.send(400, "text/plain", "Bad Request");
    }
}

int sh_getBrightness()
{
    // get brightness
    int brightness = line_getBrightness(&line);
    server.send(200, "text/plain", String(brightness).c_str());
}

void sh_brightness()
{
    if (server.method() == HTTP_GET)
    {
        sh_getBrightness();
    }
    else if (server.method() == HTTP_POST)
    {
        sh_setBrightness();
    }
    else
    {
        server.send(405, "text/plain", "Method Not Allowed");
    }
}