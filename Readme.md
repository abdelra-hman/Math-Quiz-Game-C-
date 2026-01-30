# 🧮 Math Quiz Game (C++)

A console-based math quiz game written in C++ that tests the player's arithmetic skills across multiple difficulty levels and operation types.

---

## 🚀 Features

- Choose number of questions.
- Select difficulty level:
  - Easy
  - Medium
  - Hard
  - Mix
- Select operation type:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
  - Mix
- Tracks:
  - Correct answers
  - Wrong answers
  - Final result (Winner / Lose)
- Color feedback for correct/incorrect answers.
- Replay option.

---

## 🛠️ Requirements

- Windows OS (uses `windows.h` and `system("color")`)
- C++ compiler (e.g., g++, MSVC, or MinGW)

---

## ▶️ How to Run

1. Save the code in a file named:
   MathGame.cpp

2. Compile:
   g++ MathGame.cpp -o MathGame

3. Run:
   MathGame

---

## 🎮 How to Play

1. Enter how many questions you want.
2. Choose the difficulty level:
   - 1 → Easy
   - 2 → Medium
   - 3 → Hard
   - 4 → Mix
3. Choose the operation type:
   - 1 → +
   - 2 → -
   - 3 → *
   - 4 → /
   - 5 → Mix
4. Answer each question.
5. At the end, your score and result will be displayed.
6. Choose whether to play again.

---

## 🧾 Sample Output

How Many Questions Do You Want? 5  

enter the question level 1[easy] 2[mid] 3[hard] 4[Mix] ? 2  

Enter the operation Type 1[+] 2[-] 3[*] 4[/] 5[mix] ? 5  

Question [1]  

23

17  *

--------  
391  

Correct Answer  

------------  
...  
*************************************************  
______Round = 5  
______Final Result = Winner  
______Correct Answer : 4  
______Wrong Answer : 1  
______Operation_type : Mix  
______Question Type  :  Medium  
*************************************************  
Do you want play again y/n  

---

## 📌 Notes

- Division uses integer division.
- Input validation is implemented for number of rounds.
- Color effects work on Windows only.

---


