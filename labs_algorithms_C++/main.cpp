#include <iostream>
#include <vector>
#include <algorithm>  
#include <ctime>      
#include <random>  
#include <windows.h>

#include "Lab_1.h"

#include "Lab_2_task_1.h"
#include "Lab_2_task_2.h"
#include "Lab_2_task_3.h"

#include "Lab_3_task_1.h"
#include "Lab_3_task_2.h"

#include "Lab_4_task_1.h"
#include "Lab_4_task_2.h"
#include "Lab_4_task_3.h"

#include "Lab_5_task_1.h"
#include "Lab_5_task_2.h"
#include "Lab_5_task_3.h"


#include "Lab_6_task_1.h"
#include "Lab_6_task_2.h"
#include "Lab_6_task_3.h"


#include "Lab_7_task_1.h"
#include "Lab_7_task_2.h"
#include "Lab_7_task_3.h"

using namespace std;

void hub_lab_2()
{
    cout << "\n";
    cout << "Task_1" << endl;
    lab_2_task_1();
    cout << "Task_2" << endl;
    lab_2_task_2();
    cout << "Task_3" << endl;
    lab_2_task_3();
}

void hub_lab_3()
{
    cout << "\n";
    cout << "Task_1" << endl;
    lab_3_task_1();
    cout << "Task_2" << endl;
    lab_3_task_2();
    cout << "Task_3" << endl;
}



void hub_lab_4()
{
    cout << "\n";
    cout << "Task_1" << endl;
    lab_4_task_1();
    cout << "Task_2" << endl;
    lab_4_task_2();
    cout << "Task_3" << endl;
    lab_4_task_3();
}


void hub_lab_5()
{
    cout << "\n";
    cout << "Task_1" << endl;
    lab_5_task_1();;
    cout << "Task_2" << endl;
    lab_5_task_2();
    cout << "Task_3" << endl;
    lab_5_task_3();
}


void hub_lab_6()
{
    cout << "\n";
    cout << "Task_1" << endl;
    lab_6_task_1();
    cout << "Task_2" << endl;
    lab_6_task_2();
    cout << "Task_3" << endl;
    lab_6_task_3();
}


void hub_lab_7()
{
    cout << "\n";
    cout << "Task_1" << endl;
    lab_7_task_1();
    cout << "Task_2" << endl;
    //lab_7_task_2();
    cout << "Task_3" << endl;
    lab_7_task_3();
}
/*
*/
int main() 
{
    SetConsoleOutputCP(1251);

    cout << "**********Lab_1**********\n";
    hub_lab_1();
    cout << "**********Lab_2**********\n";
    hub_lab_2();
    cout << "**********Lab_3**********\n";
    hub_lab_3();
    cout << "**********Lab_4**********\n";
    hub_lab_4();
    cout << "**********Lab_5**********\n";
    hub_lab_5();
    cout << "**********Lab_6**********\n";
    hub_lab_6();
    cout << "**********Lab_7**********\n";
    hub_lab_7();
    
    return 0;
}
