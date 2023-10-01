/* Note:
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/


#include <iostream>
#include "Tree.h"
using namespace std;
int main(){
    Tree t;
    t.insert("kaylee", "00000001");
    t.insert("rohan", "00000002");
    t.insert("michael", "00000003");
    t.insert("teddy", "00000004");
    t.insert("teddy", "00000005");
    t.insert("katty", "00000006");
    t.insert("harley", "00000007");
    t.printInOrder();
    cout<<endl;
    t.printPostOrder();
    cout<<endl;
    t.printPreOrder();
    cout<<endl;
    t.searchId("00000005");
    t.searchName("teddy");
    cout<<endl;
    t.printLevelCount();
    return 0;
}
