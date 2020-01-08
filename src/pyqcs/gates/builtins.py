import numpy as np
from .gate import BuiltinGate, GenericGate as _GenericGate
from .circuits import SingleGateCircuit
from ..build.abc import AbstractSingleGateCircuitBuilder
from ..graph.gate import GraphGate, CLOperation, CZOperation, MeasurementOperation

class BuiltinGateBuilder(AbstractSingleGateCircuitBuilder):
    __slots__ = ["_type"]
    def __init__(self, type_, get_graph_gate, has_control=False):
        AbstractSingleGateCircuitBuilder.__init__(self)
        self._type = type_
        self.get_graph_gate = get_graph_gate
        self._has_control = has_control

    def __call__(self, act, *args):
        if((act, *args) not in self._registry):
            gate = BuiltinGate(self._type, act,*args)
            gate_graph = self.get_graph_gate(act, *args)

            uses_qbits = (1 << act)
            if(self._has_control):
                uses_qbits |= (1 << args[0])

            circuit = SingleGateCircuit(uses_qbits
                        , []
                        , self._type + "(" + ",".join((str(a) for a in args)) + ")"
                        , (self._type, act, *args)
                        , gate
                        , gate_graph)
            self._registry[(act, *args)] = circuit
        return self._registry[(act, *args)]

def _get_graph_H_gate(act, i1, i2):
    return GraphGate([CLOperation(act, 0)])
_H = BuiltinGateBuilder('H', _get_graph_H_gate)
def H(act):
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    return _H(act, 0, 0)

def _get_graph_X_gate(act, i1, i2):
    return GraphGate([CLOperation(act, 14)])
_X = BuiltinGateBuilder('X', _get_graph_X_gate)
def X(act):
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    return _X(act, 0, 0)


def _get_graph_M_gate(act, i1, i2):
    return GraphGate([MeasurementOperation(act)])
_M = BuiltinGateBuilder('M', _get_graph_M_gate)
def M(act):
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    return _M(act, 0, 0)

def _get_graph_C_gate(act, control, i2):
    return GraphGate([CLOperation(act, 0)
                    , CZOperation(act, control)
                    , CLOperation(act, 0)])
_C = BuiltinGateBuilder('C', _get_graph_C_gate, has_control=True)
def C(act, control):
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    if(act == control):
        raise ValueError("act qbit and control qbit must be different")
    return _C(act, control, 0)

CX = C
CNOT = C

_R = BuiltinGateBuilder('R', lambda i0, i1, i2: None)
def R(act, r):
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    return _R(act, 0, r)

def _get_graph_Z_gate(act, i1, i2):
    return GraphGate([CLOperation(act, 5)])
_Z = BuiltinGateBuilder('Z', _get_graph_Z_gate)
def Z(act):
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    return _Z(act, 0, 0)

def _get_graph_B_gate(act, control, i2):
    return GraphGate([CZOperation(act, control)])
_B = BuiltinGateBuilder('B', _get_graph_B_gate, has_control=True)
def CZ(act, control):
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    if(act == control):
        raise ValueError("act qbit and control qbit must be different")
    return _B(act, control, 0)

def _get_graph_S_gate(act, i1, i2):
    return GraphGate([CLOperation(act, 1)])
_S = BuiltinGateBuilder('R', _get_graph_S_gate)
def S(act):
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    return _S(act, 0, np.pi/2)


def GenericGate(act, array):
    """
    This is the circuit builder that is used to generate 1-qbit
    generic gates.
    """
    if(act < 0):
        raise ValueError("act qbit must be >= 0")
    gate = _GenericGate(act, array)

    return SingleGateCircuit(1 << act, [], str(array), ("GenericGate", act, array), gate, None)
