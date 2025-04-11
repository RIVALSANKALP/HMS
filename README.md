# 🏥 Hospital Management System (C++)

This is a **console-based Hospital Management System** developed in C++. It allows hospital staff to manage patient data, appointments, employees, doctors, rooms, and medical reports. The project uses object-oriented programming principles and provides a simple login-based access for employees and patients.

---

## 🚀 Features

- 👨‍⚕️ **Patient Management**
  - Add new patients with insurance and billing details
  - View existing patient records
  - Mark patients as deceased and maintain death records

- 💼 **Employee Management**
  - Add and view employees with working hours and salary details

- 🧑‍⚕️ **Doctor Management**
  - Add doctors and view their specialization and experience

- 📅 **Appointment Scheduling**
  - Schedule and list appointments between patients and doctors

- 📄 **Medical Reports**
  - Create and view patient diagnosis and prescription reports

- 🛏️ **Room Allotment**
  - Allot rooms to patients and track occupancy status

---

## 🔐 Login System

- **Employee Login**
  - Username: `employee`
  - Password: `4321`

- **Patient Login**
  - Username: `patient`
  - Password: `1234`

> Only Employee login is enabled by default in `main()`.

---

## 🛠️ Technologies Used

- **Language:** C++
- **Standard Libraries:** iostream, vector, string, iomanip, ctime, sstream

---

## 📦 How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/hospital-management-cpp.git
   cd hospital-management-cpp
   ```

2. Compile the program using any C++ compiler:
   ```bash
   g++ -o hospital hospital.cpp
   ```

3. Run the executable:
   ```bash
   ./hospital
   ```

---

## 📌 Notes

- All data is stored in memory only (no file/database persistence).
- Console I/O is used for input and output.
- Extendable for features like file handling, GUI, or database integration.


