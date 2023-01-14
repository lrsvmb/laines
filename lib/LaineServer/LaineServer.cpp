#include "LaineServer.h"

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
}