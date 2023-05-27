#include<iostream>
#include"Queue.h"
#include"Client.h"
#include"Patient.h"

/*
* TODO
*
* 1)Переписать сервер, клиент -> потестить DONE
* 2)Переписать Очередь -> тест
* 2.1) Перенести в Client работающий функционал
* 3)ServerHandler
* 3.1)Считываение данных и помещение в Patient -> в Patient's
* 3.2)Patient into string/char
* 4)ClientHandler
* 4.1) get -> char/string patientInfo -> Patient и выдача
*
*/

int main() {
    /*
    Queue<Patient> q = Queue<Patient>(3);

    Patient patient_base = Patient("A", "A", "A", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
    Patient patient_base1 = Patient("B", "B", "B", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
    Patient patient_base2 = Patient("C", "C", "C", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
    Patient patient_base3 = Patient("D", "D", "D", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
    std::cout << (q.IsEmpty() ? "Queue is empty" : "Queue is not empty") << std::endl;

    q.Add(patient_base);
    q.Add(patient_base1);
    q.Add(patient_base2);
    //q.Add(patient_base3);
    q.Get();
    q.Get();

    std::cout << (q.IsFull() ? "Queue is full" : "Queue is not full") << std::endl;

    std::cout << "_____________________________________________________________" << std::endl;
    */

	Client client = Client();

	return 0;
}