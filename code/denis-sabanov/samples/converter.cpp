// ConsoleApplication3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include "AreaConverterApp.h"
#include <iostream>
using namespace std;



int main(int argc, char** argv) {
	AreaConverterApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
	

