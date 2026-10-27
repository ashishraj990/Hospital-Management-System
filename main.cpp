#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class representing a Doctor
class Doctor {
private:
    int id;
    string name;
    string specialization;
    bool isAvailable;

public:
    Doctor(int id, string name, string specialization) {
        this->id = id;
        this->name = name;
        this->specialization = specialization;
        this->isAvailable = true;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getSpecialization() const { return specialization; }
    bool getAvailability() const { return isAvailable; }
    void setAvailability(bool status) { isAvailable = status; }

    void display() const {
        cout << "| " << setw(5) << id 
             << "| " << setw(20) << left << name 
             << "| " << setw(20) << left << specialization 
             << "| " << setw(12) << left << (isAvailable ? "Available" : "On Leave") << " |" << endl;
    }
};

// Class representing a Patient
class Patient {
private:
    int id;
    string name;
    int age;
    string gender;
    string ailment;

public:
    Patient(int id, string name, int age, string gender, string ailment) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->ailment = ailment;
    }

    int getId() const { return id; }
    string getName() const { return name; }

    void display() const {
        cout << "| " << setw(5) << id 
             << "| " << setw(20) << left << name 
             << "| " << setw(5) << age 
             << "| " << setw(8) << left << gender 
             << "| " << setw(18) << left << ailment << " |" << endl;
    }
};

// Class representing an Appointment
class Appointment {
private:
    int appointmentId;
    int patientId;
    int doctorId;
    string date;

public:
    Appointment(int appGenId, int pId, int dId, string appDate) {
        appointmentId = appGenId;
        patientId = pId;
        doctorId = dId;
        date = appDate;
    }

    void display(const vector<Patient>& patients, const vector<Doctor>& doctors) const {
        string pName = "Unknown";
        string dName = "Unknown";

        for (const auto& p : patients) {
            if (p.getId() == patientId) {
                pName = p.getName();
                break;
            }
        }

        for (const auto& d : doctors) {
            if (d.getId() == doctorId) {
                dName = d.getName();
                break;
            }
        }

        cout << "| " << setw(8) << appointmentId 
             << "| " << setw(18) << left << pName 
             << "| " << setw(18) << left << dName 
             << "| " << setw(12) << date << " |" << endl;
    }
};

// Main Hospital Management System Class
class HospitalManagementSystem {
private:
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;
    int nextDoctorId = 101;
    int nextPatientId = 501;
    int nextAppointmentId = 1001;

public:
    void addDoctor() {
        string name, specialization;
        cout << "\nEnter Doctor's Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Specialization: ";
        getline(cin, specialization);

        doctors.push_back(Doctor(nextDoctorId++, name, specialization));
        cout << "\n>>> Doctor registered successfully with ID: " << nextDoctorId - 1 << " <<<\n";
    }

    void addPatient() {
        string name, gender, ailment;
        int age;
        cout << "\nEnter Patient's Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Ailment/Reason for visit: ";
        cin.ignore();
        getline(cin, ailment);

        patients.push_back(Patient(nextPatientId++, name, age, gender, ailment));
        cout << "\n>>> Patient registered successfully with ID: " << nextPatientId - 1 << " <<<\n";
    }

    void viewDoctors() const {
        if (doctors.empty()) {
            cout << "\nNo doctors registered in the system.\n";
            return;
        }
        cout << "\n------------------------------------------------------------------\n";
        cout << "|  ID | Doctor Name         | Specialization      | Status       |\n";
        cout << "------------------------------------------------------------------\n";
        for (const auto& doc : doctors) {
            doc.display();
        }
        cout << "------------------------------------------------------------------\n";
    }

    void viewPatients() const {
        if (patients.empty()) {
            cout << "\nNo patients registered in the system.\n";
            return;
        }
        cout << "\n------------------------------------------------------------------\n";
        cout << "|  ID | Patient Name        | Age  | Gender  | Ailment            |\n";
        cout << "------------------------------------------------------------------\n";
        for (const auto& pat : patients) {
            pat.display();
        }
        cout << "------------------------------------------------------------------\n";
    }

    void bookAppointment() {
        if (patients.empty() || doctors.empty()) {
            cout << "\nError: You need at least one registered patient and one doctor to book an appointment.\n";
            return;
        }

        int pId, dId;
        string date;
        bool patientFound = false, doctorFound = false;

        cout << "\nEnter Patient ID: ";
        cin >> pId;
        for (const auto& p : patients) {
            if (p.getId() == pId) {
                patientFound = true;
                break;
            }
        }

        if (!patientFound) {
            cout << "\nPatient ID not found!\n";
            return;
        }

        cout << "Enter Doctor ID: ";
        cin >> dId;
        int docIndex = -1;
        for (size_t i = 0; i < doctors.size(); ++i) {
            if (doctors[i].getId() == dId) {
                doctorFound = true;
                docIndex = i;
                break;
            }
        }

        if (!doctorFound) {
            cout << "\nDoctor ID not found!\n";
            return;
        }

        if (!doctors[docIndex].getAvailability()) {
            cout << "\nSorry, this Doctor is currently not available.\n";
            return;
        }

        cout << "Enter Appointment Date (DD/MM/YYYY): ";
        cin >> date;

        appointments.push_back(Appointment(nextAppointmentId++, pId, dId, date));
        cout << "\n>>> Appointment booked successfully! Appointment ID: " << nextAppointmentId - 1 << " <<<\n";
    }

    void viewAppointments() const {
        if (appointments.empty()) {
            cout << "\nNo scheduled appointments found.\n";
            return;
        }
        cout << "\n-------------------------------------------------------------\n";
        cout << "| Appt ID | Patient Name      | Doctor Name       | Date       |\n";
        cout << "-------------------------------------------------------------\n";
        for (const auto& app : appointments) {
            app.display(patients, doctors);
        }
        cout << "-------------------------------------------------------------\n";
    }
};

// Function for Login Security
bool loginSystem() {
    string password;
    const string correctPassword = "admin123"; // आप यहाँ अपना पासवर्ड बदल सकते हैं
    int attempts = 3;

    cout << "\n=========================================\n";
    cout << "          SYSTEM SECURITY LOGIN          \n";
    cout << "=========================================\n";

    while (attempts > 0) {
        cout << "Enter System Password: ";
        cin >> password;

        if (password == correctPassword) {
            cout << "\n>>> Access Granted! Welcome to the System. <<<\n";
            return true;
        } else {
            attempts--;
            cout << "\n[!] Incorrect Password. Attempts left: " << attempts << "\n\n";
        }
    }

    cout << ">>> Access Denied! Too many failed attempts. Exiting... <<<\n";
    return false;
}

int main() {
    // मुख्य मेनू पर जाने से पहले पासवर्ड चेक करें
    if (!loginSystem()) {
        return 0; 
    }

    HospitalManagementSystem hms;
    int choice;

    while (true) {
        cout << "\n=========================================\n";
        cout << "        HOSPITAL MANAGEMENT SYSTEM       \n";
        cout << "=========================================\n";
        cout << "1. Register New Doctor\n";
        cout << "2. Register New Patient\n";
        cout << "3. View All Doctors\n";
        cout << "4. View All Patients\n";
        cout << "5. Book an Appointment\n";
        cout << "6. View Scheduled Appointments\n";
        cout << "7. Exit Application\n";
        cout << "=========================================\n";
        cout << "Enter your selection (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1: hms.addDoctor(); break;
            case 2: hms.addPatient(); break;
            case 3: hms.viewDoctors(); break;
            case 4: hms.viewPatients(); break;
            case 5: hms.bookAppointment(); break;
            case 6: hms.viewAppointments(); break;
            case 7: 
                cout << "\nThank you for using the Hospital Management System. Exiting...\n";
                return 0;
            default: 
                cout << "\nInvalid input! Please choose a valid option (1-7).\n";
        }
    }
    return 0;
}
