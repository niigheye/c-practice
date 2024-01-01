void iteraz(int k, double eps, double x0) { //заводим функцию для вычисления итерационным методом
	double x = k * cos(x0); //задаем значения х0, которые в будущем будут заменены тем, что ввел пользователь
	int Nmax = 1;
	while (abs(x - x0) > eps and (Nmax < 100000))
	{
		x0 = x;
		x = k * cos(x0);
		Nmax++;
	}
	if (Nmax >= 100000) std::cout << "метод итераций:" << std::setw(25) << "Количество итераций превысело 100000" << std::endl;
	else {
		if (eps >= 0.000001)
			std::cout << "метод итераций:" << std::setw(25)<<std::fixed<<std::setprecision(6) << x << std::setw(27) << Nmax << std::endl;
		else
			std::cout << "метод итераций:" << std::setw(25)<<std::fixed<<std::setprecision(8) << x << std::setw(27) << Nmax << std::endl;
	}
}
void poldel(int k, double eps, double xl, double xr) {
	double fl = xl - cos(xl), fr = xr - cos(xr), x, fx;
	int Nmax = 1;
	if (fl * fr > 0)
		std::cout << "метод половинного деления:" << std::setw(12) << "нет корней на интервале" << std::endl;
	else {
		x = (xr + xl) / 2;//мы ищем середину интервала 
		while (abs(xr - xl) > eps) { //если разница между границами отрезков больше эпсилон, то мы действуем пока наш отрезок не попадет в эпсилон
			fx = x - k * cos(x);
			fl = xl - k * cos(xl);
			if (fx * fl > 0)
				xl = x; //мы двигаем левую границу до тех пор, пока не попадем в эпсилон
			else
				xr = x; //мы двигаем правую границу до тех пор,пока не попадем в эпсилон
			x = (xr + xl) / 2;//ищем новую середину
			Nmax++;
		}
		if (eps >= 0.000001)
			std::cout << "метод половинного деления:" << std::setw(12) << std::fixed << std::setprecision(6) << x << std::setw(29) << Nmax << std::endl;
		else
			std::cout << "метод половинного деления:" << std::setw(12) << std::fixed <<std::setprecision(8)<< x << std::setw(29) << Nmax << std::endl;
	}

}
void nuton(int k, double eps, double x0) {
	double fx = x0 - k * cos(x0), px = 1 + k * sin(x0), x;
	int Nmax = 1;
	x = x0 - fx / px;
	while (abs(x - x0) > eps)
	{
		x0 = x;
		fx = x0 - k * cos(x0);
		px = 1 + k * sin(x0);
		x = x0 - fx / px;
		Nmax++;
	}
	if (eps>=0.000001)
	std::cout << "метод ньютона:" << std::setw(27) << std::fixed << std::setprecision(6)<< x << std::setw(26) << Nmax << std::endl << std::endl;
	else
		std::cout << "метод ньютона:" << std::setw(27) << std::fixed << std::setprecision(8)<< x << std::setw(26) << Nmax << std::endl << std::endl;

}

