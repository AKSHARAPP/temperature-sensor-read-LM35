#include <Arduino.h>
//#include <util/delay.h>
#define TEMP_SENSOR_PIN A0
void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT); // pin 13
}

void loop()
{
  int temp_sensor_data = analogRead(TEMP_SENSOR_PIN);
  /*
   * ADC value is converted to voltage
   * vref = 5V = 5000mV
   * ADC = 10BIT Data = 2^10 = 1024
  */
  
  float output_voltage = ((float(temp_sensor_data) * 5000) / 1024);// v = (ADC Value * Vref)/1024

  /*output_voltage in mV
   * According to the data sheet output of LM35 is 10mV/°C
   *1°C = 10mV */
  float temp_in_celsius = output_voltage / 10; //voltage changed into corresponding temperature degree celsius

  if (temp_in_celsius >= 30)
  {
    /*If the temperature rises above 30 degrees Celsius,  LED blink
      every 500 milliseconds.*/
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(500);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(500);
  }
  else
  {
    /*When the temperature falls below 30 degrees Celsius,  LED
      blink every 250 milliseconds.*/
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(250);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(250);
  }
  Serial.println(temp_in_celsius);
}
