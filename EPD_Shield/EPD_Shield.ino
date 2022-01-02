const int rotary_pot    = A0;
const int led_red       = 8;
const int led_blue      = 7;
const int btn_1         = 2;
const int btn_2         = 1;


void setup()
{
  Serial.begin(9600);

  pinMode(rotary_pot, INPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(btn_1, INPUT);  // built-in pull down to ground
  pinMode(btn_2, INPUT);  // built-in pull down to ground
}

void loop()
{
  int state = 0;
  state = digitalRead(btn_1);
  if (state == HIGH) {
    blink_red();
  }
  else blink_blue();
}

void read_pot() {
  // This codeblock updates at an interval of 10Hz and
  // outputs a voltage value to the serial monitor ()
  int raw_val;
  float val;
  delay(100);
  raw_val = analogRead(rotary_pot);
  val = raw_val * 0.0048828;   // Multiplier to convert to 0-5V float.
  Serial.println(val);
}

void blink_red() {
  digitalWrite(led_red, HIGH);
  delay(300);
  digitalWrite(led_red, LOW);
  delay(300);
}

void blink_blue() {
  digitalWrite(led_blue, HIGH);
  delay(300);
  digitalWrite(led_blue, LOW);
  delay(300);
}
