
#include <Servo.h>. 
// Definimos los pines del sensor ultrasonidos.
const int trigPin = 10;
const int echoPin = 11;
// variables
long duracion;
int distancia;
Servo servoMotor; // creamos un servo objeto para controlar el servomotor
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  servoMotor.attach(12); // Definimos pin de entrada
}
void loop() {
  // el servo rota de 0 a 180 grados
  for(int ang=0;ang<=180;ang++){  
  servoMotor.write(ang);
  delay(30);
  distancia = calculaDistancia();// funcion que calcula la distancia

  // Estos puertos lo que hacen es mandar informacion al processing para que pueda leer los datos que llegan desde el arduino.
  Serial.print(ang); //Envia el angulo.
  Serial.print(","); //Envia una coma para diferenciar el angulo de la distancia.
  Serial.print(distancia); //Envia la distancia (aproximada).
  Serial.print("."); //Envia un punto para finalizar los elementos de la serie.(Esto lo usaremos para diferenciar datos en el procesing).
  }
 //Repetimos lo anterior teniendo en cuenta que nuestro radar vuelve a la posicion inicial.
  for(int ang=180;ang>0;ang--){  
  servoMotor.write(ang);
  delay(30);
  distancia = calculaDistancia();
  Serial.print(ang);
  Serial.print(",");
  Serial.print(distancia);
  Serial.print(".");
  }
}
// Funcion que calcula la distancia
int calculaDistancia(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH); 
  distancia= duracion*0.034/2; // calculamos las distancia de los objetos a partir de la duración al encontrar dicho objeto y la velocidad de onda en encontrarlo
  return distancia;
}
