#include <iostream>
#include <valarray>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

int main() {


    //double qm = 1.056431647689331e+03;//qm
    //double em = 0.054900489000000;

    double qm = 85.757740973643280;//qs
    double em = 0.016719000000000;//es

    //double qm = 85.757841328465590;//qs_ti

    double Em = qm;        // выбираем такой начальную точку схождения
    int32_t kepler_cnt = 0;
    double kepler_delta;
    do {
        kepler_delta = (qm - (Em - em * sin(Em)))/(1.0 - em*cos(Em));
        Em += kepler_delta;
        kepler_cnt++;
        std::cout << std::fixed << std::setprecision(15) << Em << std::endl;
        std::cout << std::fixed << std::setprecision(10) << (Em - em * sin(Em)) << std::endl;
        std::cout << std::fixed << std::setprecision(10) << qm << std::endl;
        std::cout << std::fixed << std::setprecision(10) << (1.0 - em*cos(Em)) << std::endl;
        std::cout << std::fixed << std::setprecision(10) << kepler_delta << std::endl;
        std::cout << std::fixed << std::setprecision(10) << kepler_cnt << std::endl<< std::endl;
    } while ((fabs(kepler_delta) > 1.0e-8) && (kepler_cnt < 100));
//std::cout << Em << std::endl;
  //  std::cout << kepler_cnt << std::endl;
    //std::cout << kepler_delta << std::endl;
}
