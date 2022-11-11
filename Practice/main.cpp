
#include "Data.h"

int main()
{
    RationalNumbers result;
    RationalNumbers a(7, 8);
    RationalNumbers b(3, 4);
    RationalNumbers c(3);
    RationalNumbers d(std::cin);

    result.plus(a.division(b),c.division(d));//a / b + c / d
    result.output(std::cout);

    result.divide(result.plus(a.multiplication(d),b.multiplication(c)),b.multiplication(d));// (a * d + b * c) / (b * d)
    result.output(std::cout);

    result.minus(a.division(b), c.division(d));//a / b - c / d
    result.output(std::cout);

    result.divide(result.minus(a.multiplication(d),b.multiplication(c)),b.multiplication(d));//(a * d - b * c) / (b * d)
    result.output(std::cout);

    result.divide(a.division(b), c.division(d));//(a / b) / (c / d)
    result.output(std::cout);

    result.divide(a.multiplication(d),c.multiplication(b));//(a * d) / (c * b)
    result.output(std::cout);

    result.byminusone(a.division(b));//- (a / b)
    result.output(std::cout);

    result.ismore(a.division(b),c.division(d));//(a / b) > (c / d)
    result.outputbool(std::cout);

    result.iseaqual(a.division(b), c.division(d));//(a / b) = = (c / d)
    result.outputbool(std::cout);
}

