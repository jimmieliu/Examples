#define PY_SSIZE_T_CLEAN
#include "header/Python.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

char* test(const char* inp)
{
  std::string rtn;

  for (size_t i = 0; i < 3; i++){
    rtn += inp;
  }

  char *cstr = new char[rtn.length() + 1];
  strcpy(cstr, rtn.c_str());

  return cstr;
}

static PyObject * warp_test(PyObject *self, PyObject *args) {
    const char* inp;
    if (!(PyArg_ParseTuple(args, "s", &inp))) {
        return NULL;
    }
    return (PyObject *)Py_BuildValue("s", test(inp));
}

static PyMethodDef DemoMethods[] = {
    {"test", warp_test, METH_VARARGS, "test method."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef demomodule = {
    PyModuleDef_HEAD_INIT,
    "demo",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    DemoMethods
};

PyMODINIT_FUNC
PyInit_demo(void)
{
    return PyModule_Create(&demomodule);
}

// int
// main(int argc, char *argv[])
// {
//     wchar_t *program = Py_DecodeLocale(argv[0], NULL);
//     if (program == NULL) {
//         fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
//         exit(1);
//         // char s[] = "hello";
//         // printf("%s\n", _txt2txt(s));
//     }
// 
//     /* Add a built-in module, before Py_Initialize */
//     PyImport_AppendInittab("cpsr", PyInit_cpsr);
// 
//     /* Pass argv[0] to the Python interpreter */
//     Py_SetProgramName(program);
// 
//     /* Initialize the Python interpreter.  Required. */
//     Py_Initialize();
// 
//     /* Optionally import the module; alternatively,
//        import can be deferred until the embedded script
//        imports it. */
//     PyImport_ImportModule("cpsr");
// 
// 
//     PyMem_RawFree(program);
//     return 0;
// }
