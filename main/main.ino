/*
 * 红外连线
 * OUY 10
 * VCC 5V
 * GND GND
 * 
 * 电位器与LCD连线
 * 电位器1脚 5V
 * 电位器2脚 V0
 * 电位器3脚 GND VSS RW
 * RS 12
 * E 11
 * D4 5
 * D5 4
 * D6 3
 * D7 2
 */
#include <Arduino.h>
#include <IRremote.h>
#include <LiquidCrystal.h> //调用LCD1602库

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LiquidCrystal 对象名称(寄存器选择, 使能, 数据脚, 数据脚, 数据脚， 数据脚);
int RECV_PIN = 10;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //初始化红外遥控
  pinMode(12, 1);
  lcd.begin(16, 2);               //设置LCD的行列数
  lcd.print("LCD1602 Conneted!"); //在屏幕上打印hello, world！
}

void loop()
{
  if (irrecv.decode(&results))
  {
    lcd.clear();
    switch (results.value) //确认接收到的编码。
    {
      case 16724175:
        lcd.print("1!");
        break;
      case 16718055:
        lcd.print("2!");
        break;
      case 16743045:
        lcd.print("3!");
        break;
      case 16716015:
        lcd.print("4!");
        break;
      case 16726215:
        lcd.print("5!");
        break;
      case 16734885:
        lcd.print("6!");
        break;
      case 16728765:
        lcd.print("7!");
        break;
      case 16730805:
        lcd.print("8!");
        break;
      case 16732845:
        lcd.print("9!");
        break;
      default :
        lcd.print("press too long!");
    }
    irrecv.resume(); // 接收下一个值
  }
}
