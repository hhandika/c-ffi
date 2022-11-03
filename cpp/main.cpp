#include <iostream>
#include <vector>

// Tell C++ compiler this is C code.
extern "C"
{
#include "vector.h"
}

using namespace std;

int main(void)
{
    print_hello();
    // Here we use CPP std::vector to store the data.
    vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> y = {10.0, 20.0, 30.0, 40.0, 50.0};

    // We pass the pointer to the C function.
    // C array requires the size of the array.
    // We can also do &vec[0] to get the pointer.
    // But, this is the cleanest way, I think.
    print_vectors(x.data(), x.size());

    // C function returns a pointer to the array.
    int size = 5;
    double *ones = vec_ones(size);

    // We can convert array to vector.
    vector<double> ones_vec(ones, ones + size);
    cout << "Vector ones: ";
    print_vectors(ones_vec.data(), ones_vec.size());

    // Or print it directly.
    cout << "Vector ones direct: ";
    print_vectors(ones, size);

    // Free the memory.
    delete ones;

    double *add_res = add_vectors(x.data(), y.data(), x.size());
    cout << "Vector addition: ";
    print_vectors(add_res, x.size());

    delete add_res;

    double *sub_res = substract_vectors(x.data(), y.data(), x.size());
    cout << "Vector substraction: ";
    print_vectors(sub_res, x.size());

    delete sub_res;

    double *mul_res = multiply_vectors(x.data(), y.data(), x.size());
    cout << "Vector multiplication: ";
    print_vectors(mul_res, x.size());

    delete mul_res;

    cout << "Sum vector x: " << sum(x.data(), x.size()) << endl;

    double *csum = cumsum(x.data(), x.size());
    cout << "Cumsum vector x: ";
    print_vectors(csum, x.size());

    delete csum;

    cout << "Dot product: " << dot_product(x.data(), y.data(), x.size()) << endl;

    cout << "Sum of square X: " << sum_of_square(x.data(), x.size()) << endl;
    cout << "Sum of square Y: " << sum_of_square(y.data(), y.size()) << endl;
    cout << "Magnitude X: " << magnitude(x.data(), x.size()) << endl;
    cout << "Distance: " << distance(x.data(), y.data(), x.size()) << endl;
}
