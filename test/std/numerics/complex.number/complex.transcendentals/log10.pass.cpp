//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <complex>

// template<class T>
//   complex<T>
//   log10(const complex<T>& x);

#include <complex>
#include <cassert>

#include "../cases.h"

template <class T>
void
test(const std::complex<T>& c, std::complex<T> x)
{
    assert(log10(c) == x);
}

template <class T>
void
test()
{
    test(std::complex<T>(0, 0), std::complex<T>(-INFINITY, 0));
}

void test_edges()
{
    const double pi = std::atan2(+0., -0.);
    const unsigned N = sizeof(testcases) / sizeof(testcases[0]);
    for (unsigned i = 0; i < N; ++i)
    {
        std::complex<double> r = log10(testcases[i]);
        std::complex<double> z = log(testcases[i])/std::log(10);
        if (std::isnan(real(r)))
            assert(std::isnan(real(z)));
        else
        {
            assert(real(r) == real(z));
            assert(std::signbit(real(r)) == std::signbit(real(z)));
        }
        if (std::isnan(imag(r)))
            assert(std::isnan(imag(z)));
        else
        {
            assert(imag(r) == imag(z));
            assert(std::signbit(imag(r)) == std::signbit(imag(z)));
        }
    }
}

int main()
{
    test<float>();
    test<double>();
    test<long double>();
    test_edges();
}
