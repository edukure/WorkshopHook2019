/* WORKSHOP HOOK 2019
 * Pegar dados do acelerômetro do Módulo GY-521
 * utilizando a biblioteca MPU6050

 ** Montagem para Arduino UNO e Nano
 * VCC => 5V
 * GND => GND
 * SCL => A5
 * SDA => A4

 * * Montagem para Arduino Mega
 * VCC => 5V
 * GND => GND
 * SCL => SCL
 * SDA => SDA
 */

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

//Endereco I2C do MPU6050
const int MPU = 0x68;

//Variaveis para armazenar valores dos sensores
int AcX, AcY, AcZ;
double AX, AY, AZ;

const float gravidade = 9.78;

double DoubleMap(double input, double minInput, double maxInput, double minOutput, double maxOutput)
{
  return (input - minInput) * (maxOutput - minOutput) / (maxInput - minInput) + minOutput;
}

void setup()
{
  Serial.begin(38400); //apenas para monitoramento
  //Caso o seu monitor/plotter serial não estejam mostrando os dados corretamente,
  //lembrem-se verificar se o baudrate (velocidade) está igual a do código!!
  
  Wire.begin(); //necessário para comunicação I2C
}


void loop()
{
  //Aceleração
  AcX = mpu.getAccelerationX();
  AcY = mpu.getAccelerationY();
  AcZ = mpu.getAccelerationZ();

  AX = DoubleMap((double)AcX, - 32768.00, +32768.00, 2, -2);
  AX = DoubleMap((double)AcY, -32768.00, +32768.00, 2, -2);
  AX = DoubleMap((double)AcZ, -32768.00, +32768.00, 2, -2);


  Serial.print("Aceleração eixo X: ");
  Serial.print(AX * gravidade);
  Serial.print(", Aceleração eixo Y: ");
  Serial.print(AY * gravidade);
  Serial.print(", Aceleração eixo Z: ");
  Serial.println(AZ * gravidade);

  delay(20);
}
