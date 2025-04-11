#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <sstream>  // For converting int to string in older compilers

using namespace std;

// ------------------------ Structures aur Classes -------------------------

class Patient {
public:
    int id;
    string name;
    int age;
    string gender;
    string disease;
    string admitDate;
    int roomNumber;
    string insuranceCompany;
    float insuranceCoverage;
    float billAmount;
    bool isDeceased;
    string deathDate;
};

class Employee {
public:
    int id;
    string name;
    string designation;
    float salary;
    int workingHours;
};

class Doctor {
public:
    int id;
    string name;
    string specialization;
    int experienceYears;
};

class Room {
public:
    int roomNumber;
    string type;
    bool isOccupied;
};

class DiseaseRecord {
public:
    string diseaseName;
    string startDate;
    string severity;
};

class Appointment {
public:
    int patientId;
    int doctorId;
    string date;
    string time;
    string reason;
};

class MedicalReport {
public:
    int patientId;
    string reportDate;
    string diagnosis;
    string prescription;
};

// ------------------------ Global Vectors -------------------------

vector<Patient> patients;
vector<Employee> employees;
vector<Doctor> doctors;
vector<Room> rooms;
vector<DiseaseRecord> diseases;
vector<Appointment> appointments;
vector<MedicalReport> reports;

// ------------------------ Utility Functions -------------------------

string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << (1900 + ltm->tm_year) << "-" << (1 + ltm->tm_mon) << "-" << ltm->tm_mday;
    return ss.str();
}

// ------------------------ Login -------------------------

bool loginSystem(string role) {
    string username, password;
    cout << "\n[" << role << " Login]\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if ((role == "Patient" && username == "patient" && password == "1234") ||
        (role == "Employee" && username == "employee" && password == "4321")) {
        cout << "Login successful!\n";
        return true;
    }
    cout << "Invalid credentials!\n";
    return false;
}

// ------------------------ Room Functions -------------------------

void allotRoomToPatient(int roomNo) {
    for (int i = 0; i < rooms.size(); ++i) {
        if (rooms[i].roomNumber == roomNo) {
            rooms[i].isOccupied = true;
            return;
        }
    }
    Room r = {roomNo, "General", true};
    rooms.push_back(r);
}

// ------------------------ Patient Functions -------------------------

void addPatient() {
    Patient p;
    p.id = patients.size() + 1;

    cout << "\n[Add Patient]\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Age: ";
    cin >> p.age;
    cout << "Gender: ";
    cin >> p.gender;
    cout << "Disease: ";
    cin.ignore();
    getline(cin, p.disease);
    p.admitDate = getCurrentDate();
    cout << "Room Number: ";
    cin >> p.roomNumber;
    allotRoomToPatient(p.roomNumber);
    cout << "Insurance Company: ";
    cin.ignore();
    getline(cin, p.insuranceCompany);
    cout << "Insurance Coverage (Rs): ";
    cin >> p.insuranceCoverage;
    cout << "Estimated Bill Amount: ";
    cin >> p.billAmount;
    p.isDeceased = false;
    p.deathDate = "";

    patients.push_back(p);
    DiseaseRecord d = {p.disease, p.admitDate, "Moderate"};
    diseases.push_back(d);

    cout << "Patient added successfully!\n";
}

void viewPatients() {
    cout << "\n[Patients List]\n";
    for (int i = 0; i < patients.size(); ++i) {
        Patient p = patients[i];
        cout << "------------------------------\n";
        cout << "ID: " << p.id
             << "\nName: " << p.name
             << "\nAge: " << p.age
             << "\nGender: " << p.gender
             << "\nDisease: " << p.disease;
        if (p.isDeceased) cout << " (Deceased)";
        cout << "\nAdmit Date: " << p.admitDate
             << "\nRoom No: " << p.roomNumber
             << "\nInsurance: " << p.insuranceCompany
             << "\nCoverage: Rs." << p.insuranceCoverage
             << "\nBill: Rs." << p.billAmount << "\n";
    }
}

void markAsDeceased() {
    int id;
    cout << "Patient ID to mark deceased: ";
    cin >> id;
    for (int i = 0; i < patients.size(); ++i) {
        if (patients[i].id == id) {
            patients[i].isDeceased = true;
            patients[i].deathDate = getCurrentDate();
            cout << "Marked as deceased.\n";
            return;
        }
    }
    cout << "Patient not found.\n";
}

void viewDeathRecords() {
    cout << "\n[Death Records]\n";
    for (int i = 0; i < patients.size(); ++i) {
        if (patients[i].isDeceased) {
            cout << "------------------------------\n";
            cout << "ID: " << patients[i].id
                 << "\nName: " << patients[i].name
                 << "\nDeath Date: " << patients[i].deathDate << "\n";
        }
    }
}

// ------------------------ Employee Functions -------------------------

void addEmployee() {
    Employee e;
    e.id = employees.size() + 1;

    cout << "\n[Add Employee]\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, e.name);
    cout << "Designation: ";
    getline(cin, e.designation);
    cout << "Salary: ";
    cin >> e.salary;
    cout << "Working Hours: ";
    cin >> e.workingHours;

    employees.push_back(e);
    cout << "Employee added.\n";
}

void viewEmployees() {
    cout << "\n[Employees List]\n";
    for (int i = 0; i < employees.size(); ++i) {
        Employee e = employees[i];
        cout << "------------------------------\n";
        cout << "ID: " << e.id
             << "\nName: " << e.name
             << "\nDesignation: " << e.designation
             << "\nSalary: Rs." << e.salary
             << "\nHours: " << e.workingHours << "\n";
    }
}

// ------------------------ Doctor Functions -------------------------

void addDoctor() {
    Doctor d;
    d.id = doctors.size() + 1;

    cout << "\n[Add Doctor]\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, d.name);
    cout << "Specialization: ";
    getline(cin, d.specialization);
    cout << "Experience (Years): ";
    cin >> d.experienceYears;

    doctors.push_back(d);
    cout << "Doctor added.\n";
}

void viewDoctors() {
    cout << "\n[Doctor List]\n";
    for (int i = 0; i < doctors.size(); ++i) {
        Doctor d = doctors[i];
        cout << "------------------------------\n";
        cout << "ID: " << d.id
             << "\nName: " << d.name
             << "\nSpecialization: " << d.specialization
             << "\nExperience: " << d.experienceYears << " years\n";
    }
}

// ------------------------ Appointment Functions -------------------------

void scheduleAppointment() {
    Appointment a;
    cout << "\n[Schedule Appointment]\n";
    cout << "Patient ID: ";
    cin >> a.patientId;
    cout << "Doctor ID: ";
    cin >> a.doctorId;
    cout << "Date (YYYY-MM-DD): ";
    cin >> a.date;
    cout << "Time (e.g. 10:30AM): ";
    cin >> a.time;
    cin.ignore();
    cout << "Reason: ";
    getline(cin, a.reason);

    appointments.push_back(a);
    cout << "Appointment scheduled.\n";
}

void viewAppointments() {
    cout << "\n[Appointments List]\n";
    for (int i = 0; i < appointments.size(); ++i) {
        Appointment a = appointments[i];
        cout << "------------------------------\n";
        cout << "Patient ID: " << a.patientId
             << "\nDoctor ID: " << a.doctorId
             << "\nDate: " << a.date
             << "\nTime: " << a.time
             << "\nReason: " << a.reason << "\n";
    }
}

// ------------------------ Medical Report Functions -------------------------

void createReport() {
    MedicalReport r;
    cout << "\n[Create Medical Report]\n";
    cout << "Patient ID: ";
    cin >> r.patientId;
    r.reportDate = getCurrentDate();
    cin.ignore();
    cout << "Diagnosis: ";
    getline(cin, r.diagnosis);
    cout << "Prescription: ";
    getline(cin, r.prescription);

    reports.push_back(r);
    cout << "Report created.\n";
}

void viewReports() {
    cout << "\n[Medical Reports]\n";
    for (int i = 0; i < reports.size(); ++i) {
        MedicalReport r = reports[i];
        cout << "------------------------------\n";
        cout << "Patient ID: " << r.patientId
             << "\nDate: " << r.reportDate
             << "\nDiagnosis: " << r.diagnosis
             << "\nPrescription: " << r.prescription << "\n";
    }
}

// ------------------------ Menu -------------------------

void menu() {
    int choice;
    do {
        cout << "\n===== Hospital Management Menu =====\n";
        cout << "1. Add Patient\n2. View Patients\n3. Mark Deceased\n4. Death Records\n";
        cout << "5. Add Employee\n6. View Employees\n7. Add Doctor\n8. View Doctors\n";
        cout << "9. Schedule Appointment\n10. View Appointments\n";
        cout << "11. Create Medical Report\n12. View Reports\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: markAsDeceased(); break;
            case 4: viewDeathRecords(); break;
            case 5: addEmployee(); break;
            case 6: viewEmployees(); break;
            case 7: addDoctor(); break;
            case 8: viewDoctors(); break;
            case 9: scheduleAppointment(); break;
            case 10: viewAppointments(); break;
            case 11: createReport(); break;
            case 12: viewReports(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

// ------------------------ Main -------------------------

int main() {
    cout << "\n===== Welcome to Hospital Management System =====\n";
    if (loginSystem("Employee")) {
        menu();
    }
    return 0;
}

