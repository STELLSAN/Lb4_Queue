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

/*
* int main() {
    RingQueue<int> queue(5);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);

    for (RingQueue<int>::Iterator it = queue.Begin(); it != queue.End(); ++it)
        std::cout << *it << std::endl;

    std::cout << "Dequeue: " << queue.Dequeue() << std::endl;

    queue.Enqueue(6);

    for (RingQueue<int>::Iterator it = queue.Begin(); it != queue.End(); ++it)
        std::cout << *it << std::endl;

    std::cin.get();
    return 0;
}
*/

int main() {
    /*
    Queue<Patient> q = Queue<Patient>(3);

    Patient patient_base = Patient("A A A", State::NORMAL);
    Patient patient_base1 = Patient("B B B", State::NORMAL);
    Patient patient_base2 = Patient("C C C", State::NORMAL);
    Patient patient_base3 = Patient("D D D", State::NORMAL);
    std::cout << (q.IsEmpty() ? "Queue is empty" : "Queue is not empty") << std::endl;

    q.Add(patient_base);
    q.Add(patient_base1);
    q.Add(patient_base2);
    for (Queue<Patient>::Iterator it = q.begin(); it != q.end(); it++) {
        std::cout << *it;
    }

    std::cout << (q.IsFull() ? "Queue is full" : "Queue is not full") << std::endl;

    std::cout << "_____________________________________________________________" << std::endl;
    */

	Client client = Client();

	return 0;
}