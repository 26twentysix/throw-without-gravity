#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(0, "");
	int count = 0;
	double x = 0;
	double x0;
	double v1;
	double v2;
	double t0;
	double t = 0;
	double t1;
	double sumOfT = 0;
	cout << "Введите скорость плоскости и через сколько секунд с начала движения плоскости было брошено тело: " << endl;
	cin >> v1 >> t0;
	x0 = x + (v1 * t0);
	cout << "Введите скорость тела: " << endl;
	cin >> v2;
	while (x0 > x) {
		t1 = t;
		t = (x0 - x) / v2;
		cout << "Начальная координата тела - " << x << ", плоскости - " << x0 << endl;
		x = x0;
		x0 += v1 * t;
		sumOfT += t;
		cout << "Тело переместиться к координате " << x << " за " << t << " секунд, за это же время плоскость переместится к коорднате " << x0 << endl;
		if (t > t1) {
			count--;
		}
		if (t < t1) {
			count++;
		}
		if (count < -9) {
			cout << "Тело никогда не столкнется с плоскостью ";
			break;
		}
		if (abs(x0 - x) < 0.001) {
			cout << "Тело столкнулось с плоскостью на координате " << x << " с общим временем полета " << sumOfT << " c после " << count << " приближений";
			break;
		}
	}
}
