/* ternary search */
double ternarySearch(){
	double minn = a;
	double maxx = b;
	while(maxx-minn > EPS){
		double g = minn + (maxx-minn)/3;
		double h = minn + 2*(maxx-minn)/3;
		if(f(g) < f(h))		// have to write f(), calculates minima
			maxx = h;
		else
			minn = g;
	}
	return (maxx+minn)/2;
}
