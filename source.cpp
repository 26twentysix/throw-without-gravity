#include <iostream>

using namespace std;

struct Node {
	double xPlane, xBody, endTime, time;
	Node* next;
};

int main()
{
	setlocale(0, "");
	double xPlane, xBody, strtTime = 10, bodySpeed = 11, planeSpeed = 10, endTime, time = 0;
	xPlane = planeSpeed * (strtTime + time);
	xBody = bodySpeed * time;
	endTime = ((xPlane - xBody) / bodySpeed);
	time = time + endTime;
	Node* a;
	Node* b;
	a = new Node;
	a->xPlane = xPlane;
	a->xBody = xBody;
	a->endTime = endTime;
	a->time = time;
	b = new Node;
	a->next = b;
	while ((xPlane - xBody) > 0.00001)
	{
		xPlane = planeSpeed * (strtTime + time);
		xBody = bodySpeed * time;
		endTime = ((xPlane - xBody) / bodySpeed);
		time = time + endTime;
		b->xPlane = xPlane;
		b->xBody = xBody;
		b->endTime = endTime;
		b->time = time;
		b->next = new Node;
		b = b->next;
		b->next = nullptr;
	}
	b = a;
	while (a != nullptr && b->xPlane > 0)
	{
		cout << "Координата плоскости = " << b->xPlane << "\n" << "Координата тела = " << b->xBody << "\n" << "Тело достигнет плоскости через " << b->endTime << "сек" << "\n" << "Время, прошедшее с момента начала движения телом = " << b->time << endl;
		a = b->next;
		delete b;
		b = a;
	}
}
