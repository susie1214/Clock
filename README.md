⏰ RPi-Digital-Clock
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Raspberry Pi](https://img.shields.io/badge/Raspberry%20Pi-A22846?style=for-the-badge&logo=Raspberry%20Pi&logoColor=white)
C++와 Raspberry Pi 4로 구현한 4-Digit 7-Segment 디지털 시계 프로젝트입니다.

✨ 주요 기능

실시간 시간 표시: 현재 시간을 시(HH)와 분(MM) 단위로 12시간 형식에 맞춰 표시합니다.

GPIO 직접 제어: libgpod 라이브러리를 사용해 C++로 라즈베리파이의 GPIO 핀을 직접 제어합니다.

멀티플렉싱(다중화): 4-Digit 7-Segment 디스플레이를 효율적으로 제어하기 위한 멀티플렉싱 기법을 적용했습니다.

자동 시간 갱신: 1분마다 자동으로 시스템 시간을 새로 가져와 화면에 반영합니다.

🛠️ 사용 기술

Language: C++

Hardware: Raspberry Pi 4, 4-Digit 7-Segment Display (Common Cathode)

Library: libgpiod

🚀 시작하기

1. 사전 준비

프로젝트 실행을 위해 libgpiod 개발 라이브러리가 필요합니다. 터미널에 아래 명령어를 입력하여 설치해주세요.

Bash

sudo apt-get update
sudo apt-get install libgpiod-dev
2. 컴파일

아래 명령어로 소스 코드를 컴파일합니다. (소스 파일 이름이 clock.cpp라고 가정합니다)

Bash

g++ clock.cpp -o clock -lstdc++ -lgpiodcxx
3. 실행

sudo 권한으로 컴파일된 파일을 실행합니다.

👇 ![KakaoTalk_20250906_111333266_02](https://github.com/user-attachments/assets/558838d9-9656-4e1a-82d3-e3f09f4ad24a)
