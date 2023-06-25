/*
Autor: Daniel Rodrigues Pereira
Data: 23/03/2023
*/

#include <SoftwareSerial.h>

const int MOTOR_A1 = 8;
const int MOTOR_A2 = 9;
const int MOTOR_B1 = 3;
const int MOTOR_B2 = 4;
const int BAUD_RATE = 9600;

const char MOVE_FORWARD = 'f';
const char MOVE_BACKWARD = 't';
const char MOVE_FORWARD_RIGHT = 'd';
const char MOVE_BACKWARD_RIGHT = 'y';
const char MOVE_FORWARD_LEFT = 'e';
const char MOVE_BACKWARD_LEFT = 'x';
const char STOP = 'p';

SoftwareSerial bt(10, 11);

inline void setMotors(int a1, int a2, int b1, int b2) {
    digitalWrite(MOTOR_A1, a1);
    digitalWrite(MOTOR_A2, a2);
    digitalWrite(MOTOR_B1, b1);
    digitalWrite(MOTOR_B2, b2);
}

void setup() {
    pinMode(MOTOR_A1, OUTPUT);
    pinMode(MOTOR_A2, OUTPUT);
    pinMode(MOTOR_B1, OUTPUT);
    pinMode(MOTOR_B2, OUTPUT);

    bt.begin(BAUD_RATE);
}

void loop() {
    char value = bt.read();

    switch (value) {
        case MOVE_FORWARD:
            setMotors(HIGH, LOW, HIGH, LOW);
            break;

        case MOVE_BACKWARD:
            setMotors(LOW, HIGH, LOW, HIGH);
            break;

        case MOVE_FORWARD_RIGHT:
            setMotors(HIGH, LOW, LOW, LOW);
            break;

        case MOVE_BACKWARD_RIGHT:
            setMotors(LOW, HIGH, LOW, LOW);
            break;

        case MOVE_FORWARD_LEFT:
            setMotors(LOW, LOW, HIGH, LOW);
            break;

        case MOVE_BACKWARD_LEFT:
            setMotors(LOW, LOW, LOW, HIGH);
            break;

        case STOP:
            setMotors(LOW, LOW, LOW, LOW);
            break;

        default:
            break;
    }
}

