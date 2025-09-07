#include <wiringPi.h>
#include <iostream>
#include <unistd.h>  // usleep()
#include "myClock.h" // 기존 myClock 클래스 활용 (TTL7490+7446+FND 래핑)
using namespace std;
// 세그먼트 핀 (라즈베리파이 GPIO 번호 → wiringPi 기준)
int segPins[7] = {0, 1, 2, 3, 4, 5, 6};  // a,b,c,d,e,f,g
int digitPins[4] = {21, 22, 23, 24};      // 4자리 선택 핀
// 한 자리 숫자를 FND에 출력
void displayDigit(int digitIndex, char segOut[7]) {
    // 자리 선택 (해당 자리 ON, 나머지 OFF)
    for (int i=0; i<4; i++) {
        digitalWrite(digitPins[i], (i == digitIndex) ? LOW : HIGH);
    }
    // 세그먼트 출력
    for (int i=0; i<7; i++) {
        digitalWrite(segPins[i], (segOut[i] == '1') ? HIGH : LOW);
    }
}
int main() {
    wiringPiSetup();
    // 핀모드 설정
    for (int i=0; i<7; i++) pinMode(segPins[i], OUTPUT);
    for (int i=0; i<4; i++) pinMode(digitPins[i], OUTPUT);
    // HH:mm을 위한 카운터
    myClock h1(2, 10), h10(1, 3);   // 시
    myClock m1, m10(0, 6);         // 분
    while (true) {
        // 1분마다 분 카운터 증가 (테스트용으로는 1초마다 증가시켜도 됨)
        sleep(60);  // 실제 동작: 60초마다 갱신
        // sleep(1); // 테스트용: 1초마다 갱신
        // 분 증가
        m1.clockin(1);
        if (m1.getCount() == 0) { // 분 1자리 오버 → 분 10자리 증가
            m10.clockin(1);
            if (m10.getCount() == 0) { // 분 10자리 오버 → 시 증가
                h1.clockin(1);
                if ((h10.getCount() == 2 && h1.getCount() == 4) || h1.getCount() == 10) {
                    // 24시 → 00시로 리셋
                    h1.reset(0);
                    h10.reset(0);
                }
                if (h1.getCount() == 0) h10.clockin(1);
            }
        }
        // FND 출력 (멀티플렉싱)
        for (int refresh = 0; refresh < 100; refresh++) { // 약 100*2ms=200ms 동안 반복 출력
            char out[7];
            // Digit 0 → H10
            h10.getOutput(out);
            displayDigit(0, out);
            usleep(2000);
            // Digit 1 → H1
            h1.getOutput(out);
            displayDigit(1, out);
            usleep(2000);
            // Digit 2 → M10
            m10.getOutput(out);
            displayDigit(2, out);
            usleep(2000);
            // Digit 3 → M1
            m1.getOutput(out);
            displayDigit(3, out);
            usleep(2000);
        }
    }
    return 0;
}