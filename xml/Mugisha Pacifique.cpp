#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient* next;
};

struct Doctor {
    int doctor_id;
    string name;
    string specialization;
    Doctor* next;
};

struct Appointment {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment* next;
};

class HealthcareSystem {
private:
    Patient* patientsHead;
    Doctor* doctorsHead;
    Appointment* appointmentsHead;

public:
    HealthcareSystem() : patientsHead(NULL), doctorsHead(NULL), appointmentsHead(NULL) {}

    void registerPatient() {
    	   cout << "PATIENT REGISTRATION\n";
    cout << "_______________________\n";

        Patient* newPatient = new Patient;
        cout << "ID: ";
        cin >> newPatient->patient_id;
        if (findPatientById(newPatient->patient_id)) {
            cout << "Patient ID already exists.\n";
            delete newPatient;
            return;
        }
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newPatient->name);
        cout << "Enter Date of Birth (YYYY-MM-DD): ";
        cin >> newPatient->dob;
        cout << "Enter Gender: ";
        cin >> newPatient->gender;
        newPatient->next = patientsHead;
        patientsHead = newPatient;
        cout << "Patient registered successfully.\n";
    }

    void registerDoctor() {
    	cout << "DOCTOR REGISTRATION\n";
        cout << "_______________________\n";
        Doctor* newDoctor = new Doctor;
        cout << "ID: ";
        cin >> newDoctor->doctor_id;
        if (findDoctorById(newDoctor->doctor_id)) {
            cout << "Doctor ID already exists.\n";
            delete newDoctor;
            return;
        }
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newDoctor->name);
        cout << "Enter Specialization: ";
        getline(cin, newDoctor->specialization);
        newDoctor->next = doctorsHead;
        doctorsHead = newDoctor;
        cout << "Doctor registered successfully.\n";
    }

    void registerAppointment() {
    	
    		   cout << "APPOINTMENT REGISTRATION\n";
            cout << "_______________________\n";
    
        Appointment* newAppointment = new Appointment;
        cout << "ID: ";
        cin >> newAppointment->appointment_id;
        if (findAppointmentById(newAppointment->appointment_id)) {
            cout << "Appointment ID already exists.\n";
            delete newAppointment;
            return;
        }
        cout << "Enter Patient ID: ";
        cin >> newAppointment->patient_id;
        if (!findPatientById(newAppointment->patient_id)) {
            cout << "Patient ID does not exist.\n";
            delete newAppointment;
            return;
        }
        cout << "Enter Doctor ID: ";
        cin >> newAppointment->doctor_id;
        if (!findDoctorById(newAppointment->doctor_id)) {
            cout << "Doctor ID does not exist.\n";
            delete newAppointment;
            return;
        }
        cout << "Enter Appointment Date (YYYY-MM-DD): ";
        cin >> newAppointment->appointment_date;
        newAppointment->next = appointmentsHead;
        appointmentsHead = newAppointment;
        cout << "Appointment registered successfully.\n";
    }

    void displayPatients() {
        Patient* current = patientsHead;
        cout << "\nRegistered Patients:\n";
        while (current) {
            cout << "ID: " << current->patient_id
                 << ", Name: " << current->name
                 << ", DOB: " << current->dob
                 << ", Gender: " << current->gender << "\n";
            current = current->next;
        }
    }

    void displayDoctors() {
        Doctor* current = doctorsHead;
        cout << "\nRegistered Doctors:\n";
        while (current) {
            cout << "ID: " << current->doctor_id
                 << ", Name: " << current->name
                 << ", Specialization: " << current->specialization << "\n";
            current = current->next;
        }
    }

    void displayAppointments() {
        Appointment* current = appointmentsHead;
        cout << "\nRegistered Appointments:\n";
        while (current) {
            cout << "ID: " << current->appointment_id
                 << ", Patient ID: " << current->patient_id
                 << ", Doctor ID: " << current->doctor_id
                 << ", Date: " << current->appointment_date << "\n";
            current = current->next;
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\nMenu: \n";
            cout << "1. Register a Patient\n";
            cout << "2. Register a Doctor\n";
            cout << "3. Register an appointment\n";
            cout << "4. Display Patients\n";
            cout << "5. Display Doctors\n";
            cout << "6. Display Appointments\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    registerPatient();
                    break;
                case 2:
                    registerDoctor();
                    break;
                case 3:
                    registerAppointment();
                    break;
                case 4:
                    displayPatients();
                    break;
                case 5:
                    displayDoctors();
                    break;
                case 6:
                    displayAppointments();
                    break;
                case 7:
                    cout << "Exiting program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 7);
    }

private:
    Patient* findPatientById(int id) {
        Patient* current = patientsHead;
        while (current) {
            if (current->patient_id == id) return current;
            current = current->next;
        }
        return NULL;
    }

    Doctor* findDoctorById(int id) {
        Doctor* current = doctorsHead;
        while (current) {
            if (current->doctor_id == id) return current;
            current = current->next;
        }
        return NULL;
    }

    Appointment* findAppointmentById(int id) {
        Appointment* current = appointmentsHead;
        while (current) {
            if (current->appointment_id == id) return current;
            current = current->next;
        }
        return NULL;
    }
};

int main() {
    HealthcareSystem system;
    system.menu();
    return 0;
}

