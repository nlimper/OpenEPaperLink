
#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

void init_web();
void doImageUpload(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final);

extern void webSocketSendProcess(void *parameter);
void wsLog(String text);
void wsErr(String text);
void wsSendTaginfo(uint8_t *mac, uint8_t syncMode);
void wsSendSysteminfo();
void wsSendAPitem(struct APlist* apitem);
void wsSerial(String text);
uint8_t wsClientCount();

extern AsyncWebSocket ws;

extern SemaphoreHandle_t wsMutex;

#ifndef WEBTERMINAL_H
#define WEBTERMINAL_H

class Webterminal {
   public:
    void print(const String &text);
    void print(const char text[]);
    void print(char character);
    void print(unsigned char number, int base = DEC);
    void print(int number, int base = DEC);
    void print(unsigned int number, int base = DEC);
    void print(long number, int base = DEC);
    void print(unsigned long number, int base = DEC);
    void print(float number, int decimalPlaces = 2);
    void print(double number, int decimalPlaces = 2);
    void printf(const char *format, ...);
    void println(const String &text);
    void println(const char text[]);
};

#endif