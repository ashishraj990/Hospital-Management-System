# Hospital-Management-System
# Hospital Management System (C++)

## 💻 Application Output Features (System Flow)

Here is the step-by-step visual workflow of how the terminal application executes:

### 1. Secure Access Gateway (System Login)
```text
=========================================
          SYSTEM SECURITY LOGIN          
=========================================
Enter System Password: admin123

>>> Access Granted! Welcome to the System. <<<
```

### 2. Primary Navigation Control Dashboard
```text
=========================================
        HOSPITAL MANAGEMENT SYSTEM       
=========================================
1. Register New Doctor
2. Register New Patient
3. View All Doctors
4. View All Patients
5. Book an Appointment
6. View Scheduled Appointments
7. Exit Application
=========================================
Enter your selection (1-7): 1
```

### 3. Registering a Medical Practitioner (Auto IDs 101+)
```text
Enter Doctor's Name: Dr. Alok Kumar
Enter Specialization: Cardiologist

>>> Doctor registered successfully with ID: 101 <<<
```

### 4. Patient Onboarding Registry (Auto IDs 501+)
```text
Enter Patient's Name: Rahul Sharma
Enter Age: 28
Enter Gender: Male
Enter Ailment/Reason for visit: Chest Pain

>>> Patient registered successfully with ID: 501 <<<
```

### 5. Grid View: Registered Doctors Roster
```text
------------------------------------------------------------------

|  ID | Doctor Name         | Specialization      | Status       |
------------------------------------------------------------------

|   101| Dr. Alok Kumar      | Cardiologist        | Available    |
------------------------------------------------------------------
```

### 6. Grid View: Registered Patients Logs
```text
------------------------------------------------------------------

|  ID | Patient Name        | Age  | Gender  | Ailment            |
------------------------------------------------------------------

|   501| Rahul Sharma        | 28   | Male    | Chest Pain         |
------------------------------------------------------------------
```

### 7. Core Action: Availability Validation & Appointment Booking
```text
Enter Patient ID: 501
Enter Doctor ID: 101
Enter Appointment Date (DD/MM/YYYY): 28/10/2026

>>> Appointment booked successfully! Appointment ID: 1001 <<<
```

### 8. Live View: Active Appointment Schedules
```text
-------------------------------------------------------------

| Appt ID | Patient Name      | Doctor Name       | Date       |
-------------------------------------------------------------

|     1001| Rahul Sharma      | Dr. Alok Kumar    | 28/10/2026 |
-------------------------------------------------------------
```
