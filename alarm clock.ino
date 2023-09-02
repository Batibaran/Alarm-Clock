#include <LiquidCrystal.h>

int hour = 0;
int min = 0;
int sec = 0;

int fnc_setHour = 1;
int fnc_setAlarm = 1;

int flag_clock = 0;
int flag_alarm = 0;
int status_button1 = 0;

int status_alarm = 0;
int alarm = 0;
int onoff_alarm = 0;

int hour_alarm = 0;
int minute_alarm = 0;

int state = 0, Loadstate = 0;
int cstate = 0, cLoadstate = 0;
int fstate = 0, fLoadstate = 0;
int gstate = 0, gLoadstate = 0;

float pressLenght_ms = 0;

LiquidCrystal lcd(7, 12, 2, 3, 4, 13);


void fnc_set_Clock() {
	while (fnc_setHour == 1) {

		if (digitalRead(6) == HIGH && flag_clock == 0) {
			lcd.setCursor(3, 0);
			lcd.blink();
			delay(500);
			lcd.setCursor(4, 0);
			lcd.blink();
			delay(500);
		}

		if (digitalRead(6) == LOW && flag_clock == 0) {
			lcd.noBlink();
			delay(500);
			min++;
			lcd.setCursor(3, 0);
			if (min == 1 || min == 2 || min == 3 || min == 4 || min == 5 || min == 6 || min == 7 || min == 8 || min == 9) {
				lcd.print("0");
				lcd.print(min);
			}
			else lcd.print(min);

		}

		if (digitalRead(10) == LOW && flag_clock == 0) {
			lcd.setCursor(0, 0);
			lcd.blink();
			delay(500);
			lcd.setCursor(1, 0);
			lcd.blink();
			delay(500);
			flag_clock = 1;
		}

		if (digitalRead(6) == LOW && flag_clock == 1 && status_button1 == 1) {
			lcd.noBlink();
			delay(500);
			hour++;
			lcd.setCursor(0, 0);
			if (hour == 1 || hour == 2 || hour == 3 || hour == 4 || hour == 5 || hour == 6 || hour == 7 || hour == 8 || hour == 9) {
				lcd.print("0");
				lcd.print(hour);
			}
			else if (hour == 24) {
				lcd.print("00");
			}
			else lcd.print(hour);
		}

		if (digitalRead(6) == LOW && flag_clock == 1 && status_button1 == 0) {
			lcd.noBlink();
			delay(500);
			hour++;
			lcd.setCursor(0, 0);
			if (hour == 0) {
				lcd.print("0");
				lcd.print(hour);
			}
			else if (hour >= 1 && hour <= 9) {
				lcd.print("0");
				lcd.print(hour);

			}
			else if (hour >= 10 && hour <= 12) {
				lcd.print(hour);
			}
			else if (hour >= 13 && hour <= 21) {
				lcd.print("0");
				lcd.print(hour % 12);
			}
			else if (hour == 22 || hour == 23) {
				lcd.print(hour % 12);
			}
			else if (hour == 24) {
				lcd.print("00");
			}

			if ((hour >= 0 && hour <= 11) || (hour == 24)) {
				lcd.setCursor(3, 1);
				lcd.print("AM");
			}
			else {
				lcd.setCursor(3, 1);
				lcd.print("PM");
			}

		}

		if (digitalRead(6) == HIGH && flag_clock == 1) {
			lcd.noBlink();
			lcd.setCursor(0, 0);
			lcd.blink();
			delay(500);
			lcd.setCursor(1, 0);
			lcd.blink();
			delay(500);
		}

		if (digitalRead(10) == LOW && flag_clock == 1) {
			fnc_setHour = 0;
			lcd.noBlink();
			flag_clock = 0;
		}
	}
}



void fnc_set_Alarm() {
	while (fnc_setAlarm == 1) {

		if (digitalRead(6) == HIGH && flag_alarm == 0) {
			lcd.setCursor(13, 0);
			lcd.blink();
			delay(500);
			lcd.setCursor(14, 0);
			lcd.blink();
			delay(500);
		}

		if (digitalRead(6) == LOW && flag_alarm == 0) {
			lcd.noBlink();
			delay(500);
			minute_alarm++;
			lcd.setCursor(13, 0);
			if (minute_alarm >= 1 && minute_alarm <= 9) {
				lcd.print("0");
				lcd.print(minute_alarm);
			}
			else lcd.print(minute_alarm);
			status_alarm = 1;
		}

		if (digitalRead(11) == LOW && flag_alarm == 0) {
			lcd.setCursor(10, 0);
			lcd.blink();
			delay(500);
			lcd.setCursor(11, 0);
			lcd.blink();
			delay(500);
			flag_alarm = 1;
		}
		if (digitalRead(6) == LOW && flag_alarm == 1 && status_button1 == 1) {
			lcd.noBlink();
			delay(500);
			hour_alarm++;
			lcd.setCursor(10, 0);
			if (hour_alarm >= 1 && hour_alarm <= 9) {
				lcd.print("0");
				lcd.print(hour_alarm);
			}
			else if (hour_alarm == 24) {
				lcd.print("00");
			}
			else lcd.print(hour_alarm);
			status_alarm = 1;
		}

		if (digitalRead(6) == LOW && flag_alarm == 1 && status_button1 == 0) {
			lcd.noBlink();
			delay(500);
			hour_alarm++;
			lcd.setCursor(10, 0);
			if (hour_alarm == 0) {
				lcd.print("0");
				lcd.print(hour_alarm);
			}
			else if (hour_alarm >= 1 && hour_alarm <= 9) {
				lcd.print("0");
				lcd.print(hour_alarm);

			}
			else if (hour_alarm >= 10 && hour_alarm <= 12) {
				lcd.print(hour_alarm);
			}
			else if (hour_alarm >= 13 && hour_alarm <= 21) {
				lcd.print("0");
				lcd.print(hour_alarm % 12);
			}
			else if (hour_alarm == 22 || hour_alarm == 23) {
				lcd.print(hour_alarm % 12);
			}
			else if (hour_alarm == 24) {
				lcd.print("00");
			}
			status_alarm = 1;

			if ((hour_alarm >= 0 && hour_alarm <= 11) || (hour_alarm == 24)) {
				lcd.setCursor(15, 0);
				lcd.print("A");
			}
			else {
				lcd.setCursor(15, 0);
				lcd.print("P");
			}
		}

		if (digitalRead(6) == HIGH && flag_alarm == 1) {
			lcd.noBlink();
			lcd.setCursor(10, 0);
			lcd.blink();
			delay(500);
			lcd.setCursor(11, 0);
			lcd.blink();
			delay(500);
		}

		if (digitalRead(11) == LOW && flag_alarm == 1) {
			fnc_setAlarm = 0;
			lcd.noBlink();
			flag_alarm = 0;
		}
	}

}
//made by Baran Batı
void setup()
{
	cli();

	TCNT1 = 0;
	TCCR1A = 0;
	TCCR1B = 0;

	TCCR1B |= (1 << WGM12);
	TCCR1B |= (1 << CS12) | (1 << CS10);
	OCR1A = 15624;
	TIMSK1 |= (1 << OCIE1A);


	lcd.begin(16, 2);
	lcd.print("CLOCK STARTUP");
	lcd.setCursor(0, 1);
	lcd.print("Hello!");
	delay(3000);
	lcd.clear();


	pinMode(5, INPUT);
	digitalWrite(5, HIGH);
	pinMode(6, INPUT);
	digitalWrite(6, HIGH);
	pinMode(10, INPUT);
	digitalWrite(10, HIGH);
	pinMode(11, INPUT);
	digitalWrite(11, HIGH);

	pinMode(9, OUTPUT);

	sei();
	Serial.begin(9600);
}

void loop()
{

	int tmp = analogRead(A2);
	float voltage = (tmp * 5.0) / 1024;
	float milliVolt = voltage * 1000;
	float tmpCel = (milliVolt - 500) / 10;
	float tmpFer = (((tmpCel * 9) / 5) + 32);



	if (status_button1 == 1) {
		lcd.setCursor(10, 0);
		if (hour_alarm == 0) lcd.print("00");
		else if (hour_alarm >= 1 && hour_alarm <= 9) {
			lcd.print("0");
			lcd.print(hour_alarm);
		}
		else lcd.print(hour_alarm);
		lcd.print(":");
		lcd.setCursor(13, 0);
		if (minute_alarm == 0) lcd.print("00");
		else if (minute_alarm >= 1 && minute_alarm <= 9) {
			lcd.print("0");
			lcd.print(minute_alarm);
		}
		else lcd.print(minute_alarm);
	}
	else {
		lcd.setCursor(10, 0);
		if (hour_alarm == 0) {
			lcd.print("0");
			lcd.print(hour_alarm);
		}
		else if (hour_alarm >= 1 && hour_alarm <= 9) {
			lcd.print("0");
			lcd.print(hour_alarm);

		}
		else if (hour_alarm >= 10 && hour_alarm <= 12) {
			lcd.print(hour_alarm);
		}
		else if (hour_alarm >= 13 && hour_alarm <= 21) {
			lcd.print("0");
			lcd.print(hour_alarm % 12);
		}
		else if (hour_alarm == 22 || hour_alarm == 23) {
			lcd.print(hour_alarm % 12);
		}
		lcd.print(":");
		lcd.setCursor(13, 0);
		if (minute_alarm == 0) lcd.print("00");
		else if (minute_alarm >= 1 && minute_alarm <= 9) {
			lcd.print("0");
			lcd.print(minute_alarm);
		}
		else lcd.print(minute_alarm);
		if (hour_alarm >= 0 && hour_alarm <= 9) {
			lcd.setCursor(15, 0);
			lcd.print("A");
		}
		else {
			lcd.setCursor(15, 0);
			lcd.print("P");
		}

	}


	if (status_button1 == 1) {
		lcd.setCursor(3, 1);
		lcd.print("  ");
		lcd.setCursor(15, 0);
		lcd.print("  ");

		lcd.setCursor(0, 0);

		if (hour == 0) lcd.print("00");
		else if (hour >= 1 && hour <= 9) {
			lcd.print("0");
			lcd.print(hour);
		}
		else lcd.print(hour);
		lcd.print(":");
		if (min == 0) lcd.print("00");
		else if (min >= 1 && min <= 9) {
			lcd.print("0");
			lcd.print(min);
		}
		else lcd.print(min);
		lcd.print(":");

		if (sec == 0) lcd.print("00");
		else if (sec >= 1 && sec <= 9) {
			lcd.print("0");
			lcd.print(sec);
		}
		else lcd.print(sec);
	}
	else {
		lcd.setCursor(0, 0);

		if (hour == 0) {
			lcd.print("0");
			lcd.print(hour);
		}
		else if (hour >= 1 && hour <= 9) {
			lcd.print("0");
			lcd.print(hour);

		}
		else if (hour >= 10 && hour <= 12) {
			lcd.print(hour);
		}
		else if (hour >= 13 && hour <= 21) {
			lcd.print("0");
			lcd.print(hour % 12);
		}
		else if (hour == 22 || hour == 23) {
			lcd.print(hour % 12);
		}
		lcd.print(":");
		if (min == 0) { lcd.print("00"); }
		else if (min >= 1 && min <= 9) {
			lcd.print("0");
			lcd.print(min);
		}
		else { lcd.print(min); }
		lcd.print(":");

		if (sec == 0) { lcd.print("00"); }
		else if (sec >= 1 && sec <= 9) {
			lcd.print("0");
			lcd.print(sec);
		}
		else { lcd.print(sec); }
		if (hour >= 0 && hour <= 11) {
			lcd.setCursor(3, 1);
			lcd.print("AM");
		}
		else {
			lcd.setCursor(3, 1);
			lcd.print("PM");
		}
	}



	while (digitalRead(10) == LOW) {

		delay(100);
		pressLenght_ms = pressLenght_ms + 100;


		Serial.print("Pressed = ");
		Serial.println(pressLenght_ms);

		if (pressLenght_ms >= 3000) {

			fnc_set_Clock();

		}

		if (pressLenght_ms <= 3000 && fnc_setHour != 0) {

			if (gstate == 0 && digitalRead(10) == HIGH) {
				gstate = 1;
				gLoadstate = !gLoadstate;
			}
			if (gstate == 1 && digitalRead(10) == LOW) {
				gstate = 0;
			}
			if (gLoadstate == HIGH) {
				status_button1 = 1;
			}
			else {
				status_button1 = 0;
			}
		}

	}



	pressLenght_ms = 0;
	fnc_setAlarm = 1;

	while (digitalRead(11) == LOW) {

		delay(100);
		pressLenght_ms = pressLenght_ms + 100;

		Serial.print("Pressed = ");
		Serial.println(pressLenght_ms);
		if (pressLenght_ms >= 3000) {
			fnc_set_Alarm();
		}


		if (pressLenght_ms <= 3000) {

			if (fstate == 0 && digitalRead(11) == HIGH) {
				fstate = 1;
				fLoadstate = !fLoadstate;
			}
			if (fstate == 1 && digitalRead(11) == LOW) {
				fstate = 0;
			}
			if (fLoadstate == HIGH) {
				lcd.setCursor(9, 0);
				lcd.print("!");
				onoff_alarm = 1;
			}
			else {
				lcd.setCursor(9, 0);
				lcd.print(" ");
				onoff_alarm = 0;
			}


		}


	}


	if (state == 0 && digitalRead(6) == HIGH) {
		state = 1;
		Loadstate = !Loadstate;
	}
	if (state == 1 && digitalRead(6) == LOW) {
		state = 0;
	}
	if (Loadstate == HIGH) {
		lcd.setCursor(9, 1);
		lcd.print("F");
		lcd.setCursor(10, 1);
		lcd.print(tmpFer);
	}
	else {
		lcd.setCursor(9, 1);
		lcd.print("C");
		lcd.setCursor(10, 1);
		lcd.print(tmpCel);
	}




	if (cstate == 0 && digitalRead(5) == HIGH) {
		cstate = 1;
		cLoadstate = !cLoadstate;
	}
	if (cstate == 1 && digitalRead(5) == LOW && status_alarm != 0 && alarm == 1 && onoff_alarm != 0) {
		cstate = 0;
	}
	if (cLoadstate == HIGH) {

	}
	else {
		minute_alarm = minute_alarm + 5;
		lcd.setCursor(14, 0);
		lcd.print(minute_alarm);
		lcd.setCursor(12, 0);
		lcd.print(hour_alarm);
		cLoadstate = HIGH;
		alarm = 0;
	}

	pressLenght_ms = 0;
	fnc_setHour = 1;



	if (hour_alarm == hour && minute_alarm == min && minute_alarm != 0 && onoff_alarm == 1)
	{
		tone(9, 1000, 200);
		delay(200);
		noTone(9);
		delay(200);
		alarm = 1;
	}
	else
	{
		delay(300);
	}
}


ISR(TIMER1_COMPA_vect) {
	sec++;
	if (sec >= 60) {
		min++;
		sec = 0;
	}
	if (min >= 60) {
		hour++;
		min = 0;
	}
	if (hour >= 24) {
		hour = 0;
	}
	if (minute_alarm >= 60)
	{
		hour_alarm++;
		minute_alarm = 0;
	}
	if (hour_alarm >= 24)
	{
		hour_alarm = 0;
	}
}