# 🏫 Class Management System (C Project)

A simple and efficient C-based Class Management System that helps track students, attendance, and absentees directly from the terminal.
It uses text files for persistent storage, making it lightweight and easy to understand for beginners learning file handling in C.

## 🚀 Features

### ✅ Add Students
Easily register new students with their ID and name.

### ✅ View Students
Display the complete list of registered students.

### ✅ Take Attendance
Mark students as Present (1) or Absent (0) — the system automatically logs absentees along with the date and time.

### ✅ Save Data to Files

> students.txt → Stores student records (ID + Name).
> students_absent.txt → Logs absent students with timestamps.

✅ Persistent Data
Student and attendance data are stored in text files so information is not lost after closing the program.

## 📁 File Structure
📦 Class-Management-System
 ┣ 📜 students.c
 ┣ 📜 students.txt
 ┣ 📜 students_absent.txt
 ┗ 📜 README.md

 
## ⚙️ How It Works

When the program starts, it loads existing students from students.txt.

You can:
 - Add new students
 - View all students
 - Take attendance for the day

Absent students are automatically recorded in students_absent.txt with the current date and time.

 ## Screenshots of Porgram 

 ### Attendance 
<img width="481" height="541" alt="Screenshot 2025-10-15 185758" src="https://github.com/user-attachments/assets/a1498a06-b118-4baa-8eef-ce69904ac323" />

### View All Students
<img width="466" height="418" alt="Screenshot 2025-10-15 185921" src="https://github.com/user-attachments/assets/1a3fa1a5-208d-44e0-a8f5-b4bf0a354fbc" />

### Add Students
<img width="457" height="344" alt="Screenshot 2025-10-15 185852" src="https://github.com/user-attachments/assets/a94b703d-d70c-4416-a735-20a529323395" />

### Absent students info gets saved in 📜 students_absent.txt
<img width="401" height="255" alt="Screenshot 2025-10-15 190048" src="https://github.com/user-attachments/assets/41a6159b-9f59-4117-b7b4-f8b9da11a7c3" />

## 🛠️ Compilation & Run Instructions

> On Linux / macOS:<br>
> <img width="264" height="67" alt="image" src="https://github.com/user-attachments/assets/9b5d7f14-2996-43b0-a799-df584a4c9713" />

> On Windows (using GCC / MinGW):<br>
> <img width="297" height="68" alt="image" src="https://github.com/user-attachments/assets/ed93e388-8008-48b9-95e7-393beed6802a" />


## 💡 Learning Outcomes

This project is perfect for practicing:
- File Handling (fopen, fprintf, fscanf, fclose)
- Structures and Arrays in C
- Loops & Conditionals
- Basic Menu-driven Programming


## 👨‍💻 Author
Your Name
📧 Email: [mohammadsaalim4718@gmail.com]
🌐 GitHub: https://github.com/nullvectorcodes

## 🧾 License
This project is licensed under the MIT License — you’re free to use, modify, and distribute it.



