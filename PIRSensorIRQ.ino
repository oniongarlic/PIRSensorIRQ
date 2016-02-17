// PIR Sensor with interrupts

#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

const int pir=3;
volatile int cnt=0;
volatile int tcnt=0;

void pirTick()
{
  sleep_disable();
  cnt++;
}

void sleepNow(void)
{
  digitalWrite(13, LOW);   // turn LED off to indicate sleep
  delay(100);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu();
  sleep_disable();
  digitalWrite(13, HIGH);   // turn LED on to indicate awake
  delay(100);
}

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(pir, INPUT);
  attachInterrupt(digitalPinToInterrupt(pir), pirTick, RISING);
  
  Serial.println("PIR IRQ Test app");
  digitalWrite(13, HIGH);
  delay(100);
}

void loop() {
  if (tcnt!=cnt) {
    Serial.println(cnt);
    tcnt=cnt;
  }
  sleepNow();
}



