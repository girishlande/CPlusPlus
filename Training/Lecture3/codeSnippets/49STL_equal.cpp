

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int v1[] = { 10, 20, 30, 40, 50 };
    std::vector<int> vector_1(v1, v1 + sizeof(v1) / sizeof(int));

    // Printing vector1
    std::cout << "Vector contains : ";
    for (unsigned int i = 0; i < vector_1.size(); i++)
        std::cout << " " << vector_1[i];
    std::cout << "\n";

    vector<int> v2(vector_1);

    // using std::equal()
    // if (std::equal(vector_1.begin(), vector_1.end(), v1)); // comparing with array 
    if (std::equal(vector_1.begin(), vector_1.end(), v2.begin()))  // comparing with vector
        std::cout << "The contents of both sequences are equal.\n";
    else
        printf("The contents of both sequences differ.");

}