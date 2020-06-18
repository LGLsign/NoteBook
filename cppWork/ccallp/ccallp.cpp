#include <iostream>
#include <python2.7/Python.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

using namespace std;

int main() {
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    PyObject* pModule = PyImport_ImportModule("pytest");
    if (!pModule)
    {
        cout<< "Python Open Module 'sendRMEmail' error" << endl;
        return -1;
    }
    PyObject* pfun = PyObject_GetAttrString(pModule, "test");
    if (!pfun || !PyCallable_Check(pfun))
    {
        cout << "non func!" << endl;
        return -1;
    }

    PyObject* args = PyTuple_New(1);
    PyTuple_SetItem(args, 0, Py_BuildValue("i", 7));
    //PyTuple_SetItem(args, 1, Py_BuildValue("s", arg2));
    PyObject_CallObject(pfun, args);

    //if (pRet != NULL)
    //{
    //    string result = PyString_AsString(pRet);
    //}

    Py_Finalize();
    return 0;
}
