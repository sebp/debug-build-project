#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *add(PyObject *self, PyObject *args)
{
    long a, b;

    if (!PyArg_ParseTuple(args, "ll", &a, &b))
        return NULL;
    return PyLong_FromLong(a + b);
}

static PyMethodDef methods[] = {
    {"add", add, METH_VARARGS, "Return the sum of two integers."},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "_ext",
    "Minimal C extension for build debugging.",
    -1,
    methods,
};

PyMODINIT_FUNC PyInit__ext(void)
{
    return PyModule_Create(&module);
}
