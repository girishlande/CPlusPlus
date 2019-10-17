#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
//Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.

//__Example__

//For `inputArray = [3, 6, -2, -5, 7, 3]`, the output should be <br />`adjacentElementsProduct(inputArray) = 21`.

int findLargestProductPair(vector<int> items) {
    int product = items[0]*items[1];
    for(int i=1;i<items.size()-1;i++) {
        if (items[i]*items[i+1]>product) {
            product = items[i]*items[i+1];
        }
    }
    return product;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> items = {45,32,12,3,65,2,1};
    cout << "largest product is: " << findLargestProductPair(items);


    return a.exec();
}
