#include "Patient.h"
#include "Queue.h"
#include "Server.h"
#include "ServerHandler.h"

int main() {
	/*
	Queue<Patient> q = Queue<Patient>(3);

	Patient patient_base = Patient("A", "A", "A", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
	Patient patient_base1 = Patient("D", "D", "D", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
	Patient patient_base2 = Patient("C", "C", "C", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
	Patient patient_base3 = Patient("G", "G", "G", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
	std::cout << (q.IsEmpty() ? "Queue is empty" : "Queue is not empty") << std::endl;

	q.Push(patient_base);
	q.Push(patient_base1);
	q.Push(patient_base2);
	q.Pop();
	q.Push(patient_base3);

	std::cout << (q.IsFull() ? "Queue is full" : "Queue is not full") << std::endl;

	std::cout << "_____________________________________________________________" << std::endl;

	q.Print();
	*/
	ServerHandler test();
	

	return 0;
}










