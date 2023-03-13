#include "gpio.h"

Gpio::Gpio(int pin, int type, void (*isrInput)(void), QObject *parent) : QObject(parent)
{
    setenv("WIRINGPI_GPIOMEM", "1", 1);
    wiringPiSetup();
    m_pin = pin;
    m_toggleStatus = 0;

    switch(type)
    {
        case GPIO_INPUT:
        {
            pinMode(m_pin, INPUT);
            wiringPiISR(m_pin, INT_EDGE_BOTH, isrInput);
        } break;

        case GPIO_OUTPUT:
        {
            pinMode(m_pin, OUTPUT);

        } break;

    }
}
void Gpio::isrCallback()
{
    emit inputChanged(digitalRead(m_pin));
}

void Gpio::pinHigh()
{

    digitalWrite(m_pin,HIGH);
}

void Gpio::pinLow()
{
    digitalWrite(m_pin,LOW);
}

void Gpio::pinToggle()
{
    m_toggleStatus ^= 1;
    digitalWrite(m_pin, m_toggleStatus);
}
