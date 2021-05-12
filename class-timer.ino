#include <DS1302.h>

#include <U8g2lib.h>
#include <U8x8lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
DS1302 rtc(14, 12, 13);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("Class Timer by IvanEFan");
    
    u8g2.begin();
    u8g2.enableUTF8Print();
}

void loop() {
    // put your main code here, to run repeatedly:
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_unifont_t_chinese2);
    u8g2.setCursor(0, 14);
    u8g2.print("Resting");
    u8g2.setCursor(0, 29);
    u8g2.print("Next: Math");
    u8g2.setFont(u8g2_font_logisoso24_tr);
    u8g2.setCursor(0, 59);
    u8g2.print(rtc.time().hr);
    u8g2.print(":");
    u8g2.print(rtc.time().min);
    u8g2.print(":");
    u8g2.print(rtc.time().sec);
    u8g2.sendBuffer();
}