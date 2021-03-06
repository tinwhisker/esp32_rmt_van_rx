/*
    Arduino wrapper around the ESP32 library to monitor a 125kbps VAN bus
*/
#pragma once

#ifndef _esp32_arduino_rmt_van_rx_h
    #define _esp32_arduino_rmt_van_rx_h

    #include "esp32_rmt_van_rx.h"


    #ifdef __cplusplus
    extern "C" {
    #endif
        /* Include C code here */
    #ifdef __cplusplus
    }
    #endif

class ESP32_RMT_VAN_RX
{
private:
    uint8_t _rxPin;
    uint8_t _ledPin;
    uint8_t _channel;

public:
    ESP32_RMT_VAN_RX();
    ~ESP32_RMT_VAN_RX();

    void Receive(uint8_t *messageLength, uint8_t message[]);
    void Init(uint8_t channel, uint8_t rxPin, uint8_t ledPin);
    void Stop(uint8_t channel);
};
#endif
