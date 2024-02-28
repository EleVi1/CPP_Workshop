#include "forward_multiplication.hh"

#include <iostream>

outer_lambda_type mult_by = [](int a) { return [a](int b) { return a * b; }; };