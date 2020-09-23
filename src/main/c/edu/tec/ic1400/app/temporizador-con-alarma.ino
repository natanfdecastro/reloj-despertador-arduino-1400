//Trabajo en Arduino UNO para Fundamentos de Organizacion de Computadoras
//Integrantes: Natan Fernandez de Castro - 2017105774
//             Yanina Contreras Blanco - 2017056034
//             David Valverde Villalobos - 2017121710

#include <LiquidCrystal.h> //Se incluye la libreria para la LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Se asignan los pines digitales en Arduino para la utilizacion de la LCD
const int buzzer = 4;          //Fijo el pin para el buzzer
String tope = "0:5";           //Esta es la variable donde el valor de ella es el que se utiliza para el inicio del sonido
void setup() 
   {
    
       lcd.begin(16, 2);              // Fijo el numero de caracteres y filas
       lcd.print("Alarma ACTIVADA");  // Mensaje de impresion fijo en la lcd 
       pinMode(buzzer, OUTPUT);       // Fijo pin 4 como salida del buzzer
       
   }
void loop()
    // Esta funcion se encarga del ciclo para el conteo del reloj 
   {
       lcd.setCursor(6, 1);    // Mueve el cursor para trabajar con la fila de abajo en la posicion 6
       String s = reloj() ;    // Inicio una variable llamada s que a su vez llama a la funcion reloj 
       lcd.print(s) ;
       if(s.equals(tope)){
        activar();
        //reiniciar contador
       }
   }
String reloj()
    // Esta funcion se encarga del planteo de como se va a hacer el conteo con las variables
   {
       int n = millis() / 1000 ;       // Se utiliza una funcion millis y se divide entre mil es lo hacer pasar a segundos
       int segundos = n % 60  ;        // Luego saco el residuo de sesenta de la variable n
       int minutos =  n / 60  ;        // Y por ultimo el valor que se necesita para la variable de minutos mediante la division 

       String S = String(minutos) + ":" + String(segundos); //Aqui se acoplan las dos variables de segundos y minutos
       String tope = "0:5";
       return (S);
       
   }
void activar()
     // Funcion encargada de inicializar el buzzer para hacer sonido una vez que las variables de 'tope' y 's' coincidan  
  {
      
      
        lcd.print(" BIP");   //Print de prueba para saber que la validacion en el ciclo se cumple y entra a esta funcion
        tone(buzzer, 1000); // Envio la señal
        delay(10000);       // duracion de 10 segundos
        noTone(buzzer);     // Para el sonido
        delay(1000);        // por un segundo
      

  
  }

