#include "LineServer.h"

void server_connect(const char *ssid, const char *password)
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    // print ssid and ip adress each in one line with a space between
    Serial.print("Connected to ");
    Serial.print(ssid);
    Serial.print(" with IP ");
    Serial.println(WiFi.localIP());
}

void server_addHandle(const char *path, void (*callback)())
{
    server.on(path, callback);
}

void server_start()
{
    // add handles
    server_addHandle("/color", sh_color);
    server_addHandle("/brightness", sh_brightness);
    server_addHandle("/animation", sh_animation);
    // add not found
    server.onNotFound([]()
                      { server.send(404, "text/plain", "Not found"); });

    server.begin();
    Serial.println("Server started");
}

void server_stop()
{
    server.stop();
    Serial.println("Server stopped");
}

void server_loop()
{
    server.handleClient();
    delay(1);
}