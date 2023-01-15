#ifndef LAINESERVER_H
#define LAINESERVER_H

// make a esp8266 server with .on request
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include "ServerHandles.h"

// webserver listening for requests
ESP8266WebServer server(80);

// connect, start, stop, handle functions
void server_connect(const char *ssid, const char *password);
void server_addHandle(const char *path, void (*callback)());
void server_start();
void server_stop();
void server_loop();

#endif