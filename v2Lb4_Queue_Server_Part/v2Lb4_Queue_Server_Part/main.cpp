#include "Patient.h"
#include "Queue.h"
#include "Server.h"
#include "ServerHandler.h"

/*
* TODO
* 
* 1)���������� ������, ������ -> ��������� DONE
* 2)���������� ������� -> ����
* 2.1) ��������� � Client ���������� ����������
* 3)ServerHandler
* 3.1)����������� ������ � ��������� � Patient -> � Patient's
* 3.2)Patient into string/char
* 4)ClientHandler
* 4.1) get -> char/string patientInfo -> Patient � ������
* 5.0) ��������� ���������� � .cpp, �������� �����.h � .cpp 
* 
*/

int main() {
	/*
	Queue<Patient> q = Queue<Patient>(4);

	Patient patient_base = Patient("A", "A", "A", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
	Patient patient_base1 = Patient("B", "B", "B", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
	Patient patient_base2 = Patient("C", "C", "C", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
	Patient patient_base3 = Patient("D", "D", "D", Date{ 1,2,1980 }, State::NORMAL, Gender::MALE);
	std::cout << (q.IsEmpty() ? "Queue is empty" : "Queue is not empty") << std::endl;

	q.Add(patient_base);
	q.Add(patient_base1);
	q.Add(patient_base2);
	q.Add(patient_base3);
	//q.Get();
	//q.Add(patient_base3);

	std::cout << (q.IsFull() ? "Queue is full" : "Queue is not full") << std::endl;

	std::cout << "_____________________________________________________________" << std::endl;

	q.Print();
	*/
	ServerHandler test = ServerHandler();
	

	//Server serv = Server(); // - Is it work's MonkaGiGa

	return 0;
}










