/* Arduino version of the ESP32 RMT VAN bus receive example, 
 * displaying the received VAN messages on the serial console
 * 
 * The software is distributed under the MIT License
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
*/
#include <Arduino.h>
#include <esp32_arduino_rmt_van_rx.h>

ESP32_RMT_VAN_RX VAN_RX;

const uint8_t VAN_DATA_RX_RMT_CHANNEL = 0;
const uint8_t VAN_DATA_RX_PIN = 22;
const uint8_t VAN_DATA_RX_LED_INDICATOR_PIN = 2;

uint8_t vanMessageLength;
uint8_t vanMessage[34];

void setup()
{
    Serial.begin(112500);
    printf("ESP32 Arduino VAN bus monitor\n");

    VAN_RX.Init(VAN_DATA_RX_RMT_CHANNEL, VAN_DATA_RX_PIN, VAN_DATA_RX_LED_INDICATOR_PIN);
}

void loop()
{
    static uint32_t lastMillis = 0;

    if (millis() - lastMillis > 10)
    {
        VAN_RX.Receive(&vanMessageLength, vanMessage);

        if (vanMessageLength > 0)
        {
            for (size_t i = 0; i < vanMessageLength; i++)
            {
                if (i != vanMessageLength - 1)
                {
                    printf("%02X ", vanMessage[i]);
                }
                else
                {
                    printf("%02X", vanMessage[i]);
                }
            }
            printf("\n");
        }
    }
}