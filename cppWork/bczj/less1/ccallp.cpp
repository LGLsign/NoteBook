#include "ccallp.h"

using namespace std;

int create_million_num(string &strNum){
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    PyObject* pModule = PyImport_ImportModule("createNum");
    if (!pModule)
    {
        cout<< "Python Open Module 'createNum' error" << endl;
        return -1;
    }
    PyObject* pfun = PyObject_GetAttrString(pModule, "createMillionNum");
    if (!pfun || !PyCallable_Check(pfun))
    {
        cout << "non func!" << endl;
        return -1;
    }

    PyObject* args = PyTuple_New(0);
    //PyTuple_SetItem(args, 0, Py_BuildValue("i", 7));
    //PyTuple_SetItem(args, 1, Py_BuildValue("s", arg2));
    PyObject* pRet = PyObject_CallObject(pfun, args);

    if (pRet != NULL)
    {
        strNum = PyString_AsString(pRet);
    }

    Py_Finalize();
    return 0;
}

