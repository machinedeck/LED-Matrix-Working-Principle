int mat[8][8] = {{1, 0, 0, 0, 0, 0, 0, 1},
                 {1, 1, 0, 0, 0, 0, 0, 1},
                 {1, 0, 1, 0, 0, 0, 0, 1},
                 {1, 0, 0, 1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1, 0, 0, 1},
                 {1, 0, 0, 0, 0, 1, 0, 1},
                 {1, 0, 0, 0, 0, 0, 1, 1},
                 {1, 0, 0, 0, 0, 0, 0, 1}};
int rows[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int cols[8] = {10, 11, 12, 13, A0, A1, A2, A3};
int col_ref;
int val;
unsigned long initial_time = millis();
const int interval = 2;
int j = 0;
void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i < 8; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  // for (int j = 0; j < 8; j++) {
  //   for (int i = 0; i < 8; i++) {
  //     val = mat[i][j];
  //     if (val == 1) {
  //       digitalWrite(rows[i], HIGH);
  //       col_ref = j;
  //     }
  //     else {
  //       digitalWrite(rows[i], LOW);
  //     }
  //   }
  //   if (j != col_ref && val == 1) {
  //     digitalWrite(cols[j], HIGH);
  //   }
  //   else {
  //     digitalWrite(cols[j], LOW);
  //   }
  // }
  // delayMicroseconds(1);
  // int j = 0;

  // Trial 1
  // while (micros() - initial_time >= interval) {
  //   initial_time = micros();
  //   for (int jprime = 0; jprime < 8; jprime++) {
  //     if (jprime != j) {
  //       digitalWrite(cols[jprime], HIGH);
  //     }
  //     else {
  //       digitalWrite(cols[jprime], LOW);
  //     }
  //   }

  //   for (int i = 0; i < 8; i++) {
  //     digitalWrite(rows[i], mat[i][j]);
  //   }
  //   j++;
  //   if (j == 8) {
  //     j = 0;
  //   }
  // }


  // Trial 2
   while (millis() - initial_time >= interval) {
    initial_time = millis();

    // Focus on a specific column. If not chosen, then put to high
    for (int jprime = 0; jprime < 8; jprime++) {
      if (jprime != j) {
        digitalWrite(cols[jprime], HIGH);
      }
      else {
        digitalWrite(cols[jprime], LOW);
      }
    }

    // Check the rows. If 1, then turn on
    for (int i = 0; i < 8; i++) {
      int value = mat[i][j];

      digitalWrite(rows[i], mat[i][j]);
    }

    // Increment j to go to another column
    j++;
    if (j == 8) {
      j = 0;
    }
  }


}
