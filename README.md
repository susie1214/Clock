# ⏰ RPi-Digital-Clock

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Raspberry Pi](https://img.shields.io/badge/Raspberry%20Pi-A22846?style=for-the-badge&logo=Raspberry%20Pi&logoColor=white)

> C++와 Raspberry Pi 4로 구현한 4-Digit 7-Segment 디지털 시계 프로젝트

<br>

[Image of the working 4-digit clock on a breadboard]
*👆 여기에 실제 작동하는 시계 사진이나 GIF를 추가하면 훨씬 멋져요!*

<br>

## ✨ 주요 기능

-   **실시간 시간 표시**: 분(MM)과 초(SS)를 실시간으로 표시합니다.
-   **GPIO 직접 제어**: `libgpiod` 라이브러리를 사용해 C++로 라즈베리파이의 GPIO 핀을 제어합니다.
-   **다이나믹 드라이빙**: 4-Digit 7-Segment 디스플레이를 위한 멀티플렉싱 기법을 적용했습니다.
-   **콜론 깜빡임**: 매초마다 중앙의 콜론(:)이 깜빡이며 생동감을 더합니다.

<br>

## 🛠️ 사용 기술

-   **Language**: `C++`
-   **Hardware**: `Raspberry Pi 4`, `4-Digit 7-Segment Display (Common Cathode)`
-   **Library**: `libgpiod`

<br>

## 🚀 시작하기

### 1. 사전 준비

프로젝트 실행을 위해 `libgpiod` 라이브러리가 필요합니다.

```bash
sudo apt-get update
sudo apt-get install libgpiod-dev
```

### 2. 컴파일

아래 명령어로 소스 코드를 컴파일합니다.

```bash
g++ -o clock4 clock_4digit.cpp -lgpiodcxx
```

### 3. 실행

`sudo` 권한으로 컴파일된 파일을 실행합니다.

```bash
sudo ./clock4
```

<br>

## 👥 팀원

| 이름       | GitHub 프로필                               | 역할       |
| ---------- | ------------------------------------------- | ---------- |
| **(이름1)** | [@GitHub-Username1](https://github.com/username1) | (역할, 예: Logic) |
| **(이름2)** | [@GitHub-Username2](https://github.com/username2) | (역할, 예: H/W) |
