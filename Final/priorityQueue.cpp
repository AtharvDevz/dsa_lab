#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Patient
{
    public:
    string name;
    int priority;
    Patient(const string &name, int priority){
        this->name = name;
        this->priority = priority;
    }
};

int comparePatients(Patient* &p1, Patient* &p2){
    return (p1->priority > p2->priority);
}

int main()
{

    priority_queue<Patient, vector<Patient>, decltype(comparePatients)> patientQueue(comparePatients);

    int numPatients;
    cout << "Enter the number of patients: ";
    cin >> numPatients;
    cin.ignore();
    for (int i = 0; i < numPatients; ++i)
    {
        string name;
        int priority;
        cout << "Enter name of patient " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter priority of patient " << i + 1 << " (1 for Serious, 2 for Non serious, 3 for General Checkup): ";
        cin >> priority;
        cin.ignore();
        patientQueue.emplace(name, priority);
    }
    
    cout << "\nTreating patients:\n";
    while (!patientQueue.empty())
    {
        Patient nextPatient = patientQueue.top();
        patientQueue.pop();

        // Treat the patient (simulated by printing information)
        string priorityStr;
        if (nextPatient.priority == 1)
            priorityStr = "Serious";
        else if (nextPatient.priority == 2)
            priorityStr = "Non-serious";
        else
            priorityStr = "General Checkup";
        cout << "Name: " << nextPatient.name << ", Priority: " << priorityStr << endl;
    }
    return 0;
}