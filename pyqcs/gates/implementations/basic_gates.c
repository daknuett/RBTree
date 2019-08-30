#include <Python.h>
#include <structmember.h>
#include <numpy/ndarraytypes.h>
#include <numpy/ufuncobject.h>
#include <stddef.h>

#include "generic_setup.h"

typedef struct
{
    npy_intp act;
    npy_intp control;
    npy_float r;
} basic_gate_argument_t;

long int ipow(int base
            , int exponent)
{

    long int result;
    if(exponent == 0)
    {
        return 1;
    }
    if(exponent % 2 == 0)
    {
        result = ipow(base, exponent / 2);
        return result * result;
    }
    return base * ipow(base, exponent - 1);
                
}


static void
ufunc_X( char ** args
       , npy_intp * dimensions
       , npy_intp * steps
       , void * data)
{

    basic_gate_argument_t argument = *((basic_gate_argument_t *) data);
    npy_intp l = argument.act;
    npy_intp i;
    PYQCS_GATE_GENERIC_SETUP;

    for(i = 0; i < ndim; i++)
    {
        qm_out[i] = qm_in[i^ipow(2, l)];
    }
    *measured_out = 0;
}

static char ufunc_types[] = 
    { NPY_CFLOAT, NPY_FLOAT, NPY_CFLOAT, NPY_FLOAT, NPY_FLOAT };
static PyUFuncGenericFunction ufunc_X_funcs[] = 
    { ufunc_X };


typedef struct
{
    PyObject_HEAD
    basic_gate_argument_t argument;
    PyObject * ufunc;
    void * data[1];
} BasicGate;


static int
BasicGate_init
	( BasicGate * self
	, PyObject * args
	, PyObject * kwds)
{
	char type;

	char *kwords[] = { "type_", "coefficients", NULL};

	if(!PyArg_ParseTupleAndKeywords(args, kwds, "Clld", kwords
                , &type
                , &(self->argument.act)
                , &(self->argument.control)
                , &(self->argument.r)))
	{
		return -1;
	}
	self->data[0] = (void *)&(self->argument);

	switch(type)
	{
		case 'X':
		{
			self->ufunc = PyUFunc_FromFuncAndDataAndSignature(
				ufunc_X_funcs // func
				, self->data // data
				, ufunc_types //types
				, 1 // ntypes
				, 1 // nin
				, 1 // nout
				, PyUFunc_None // identity
				, "force_function" // name
				, "Computes the X (NOT) gate on a state." // doc
				, 0 // unused
                , "(n)(m)->(n)(m)()"); 
			break;
		}
    }
	Py_INCREF(self->ufunc);
	return 0;
}

static PyObject *
BasicGate_call
	(BasicGate * self
	 , PyObject * args
	 , PyObject * kwargs)
{
	return PyObject_Call(self->ufunc, args, kwargs);
}

static void BasicGate_dealloc(BasicGate * self)
{
    Py_XDECREF(self->ufunc);
    Py_TYPE(self)->tp_free((PyObject *) self);
}


static PyMemberDef BasicGate_members[] = 
{
	{"ufunc", T_OBJECT_EX, offsetof(BasicGate, ufunc), 0, "ufunc"},
	{NULL}
};


static PyTypeObject BasicGateType = 
{
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "pyqcs.gates.implementations.basic_gates.BasicGate",
	.tp_doc = "",
	.tp_basicsize = sizeof(BasicGate),
	.tp_itemsize = 0,
	.tp_flags = Py_TPFLAGS_DEFAULT,
	.tp_new = PyType_GenericNew,
	.tp_init = (initproc) BasicGate_init,
	.tp_call = BasicGate_call,
	.tp_members = BasicGate_members,
    .tp_dealloc = (destructor) BasicGate_dealloc
};



static PyMethodDef basic_gates_methods[] = {
	{NULL, NULL, 0, NULL}
};


static struct PyModuleDef moduledef = {
	PyModuleDef_HEAD_INIT
	, "pyqcs.gates.implementations.basic_gates"
	, NULL
	, -1
	, basic_gates_methods
	, NULL
	, NULL
	, NULL
	, NULL
};

PyMODINIT_FUNC 
PyInit_interaction(void)
{
	PyObject * module;

	if(PyType_Ready(&BasicGateType) < 0)
	{
		return NULL;
	}

	module = PyModule_Create(&moduledef);
	if(!module)
	{
		return NULL;
	}
	import_array();
	import_ufunc();

	Py_INCREF(&BasicGateType);
	PyModule_AddObject(module, "BasicGate", (PyObject *) &BasicGateType);

	return module;
}
