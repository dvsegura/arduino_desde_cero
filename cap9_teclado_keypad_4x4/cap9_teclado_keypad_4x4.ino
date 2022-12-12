#include <Key.h>
#include <Keypad.h>

/*Teclado menbrana

  F1-> 9
  F2-> 8
  F3-> 7
  F4-> 6
  C1-> 5
  C2-> 4
  C3-> 3
  C4-> 2
*/

const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// conexionado pines de arduino
byte pinesFilas[FILAS] = {9,8,7,6}; 
byte pinesColumnas[COLUMNAS] = {5,4,3,2};

Keypad teclado = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas);

void setup() {

}

void loop() {

}
