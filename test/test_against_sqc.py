import pytest
import numpy as np

from pyqcs.gates.implementations.basic_gates import BasicGate

try:
    import sqc
except:
    pytestmark = pytest.mark.skip("sqc is not present; install it to run these tests.")

def test_raw_x1():
    nbits = 2
    ndim = 2**nbits
    qm_state = np.zeros(ndim, dtype=np.cdouble)
    qm_state[0] = 1
    cl_state = np.zeros(nbits, dtype=np.double)
    gate = BasicGate('X', 0, 0, 0.0)
    state = sqc.operator(2).X(0) * sqc.state(2)

    qm_state_new, cl_state_new, measured = gate(qm_state, cl_state)

    assert state.v == pytest.approx(qm_state_new)


def test_raw_x2():
    nbits = 2
    ndim = 2**nbits
    qm_state = np.zeros(ndim, dtype=np.cdouble)
    qm_state[0] = 1
    cl_state = np.zeros(nbits, dtype=np.double)
    gate = BasicGate('X', 1, 0, 0.0)
    state = sqc.operator(2).X(1) * sqc.state(2)

    qm_state_new, cl_state_new, measured = gate(qm_state, cl_state)

    assert state.v == pytest.approx(qm_state_new)

def test_raw_h1():
    nbits = 2
    ndim = 2**nbits
    qm_state = np.zeros(ndim, dtype=np.cdouble)
    qm_state[0] = 1
    cl_state = np.zeros(nbits, dtype=np.double)
    gate = BasicGate('H', 0, 0, 0.0)
    state = sqc.operator(2).H(0) * sqc.state(2)

    qm_state_new, cl_state_new, measured = gate(qm_state, cl_state)

    assert state.v == pytest.approx(qm_state_new)

def test_raw_h2():
    nbits = 2
    ndim = 2**nbits
    qm_state = np.zeros(ndim, dtype=np.cdouble)
    qm_state[0] = 1
    cl_state = np.zeros(nbits, dtype=np.double)
    gate = BasicGate('H', 1, 0, 0.0)
    state = sqc.operator(2).H(1) * sqc.state(2)

    qm_state_new, cl_state_new, measured = gate(qm_state, cl_state)

    assert state.v == pytest.approx(qm_state_new)


def test_raw_r1():
    nbits = 2
    ndim = 2**nbits
    qm_state = np.zeros(ndim, dtype=np.cdouble)
    qm_state[0] = 1
    cl_state = np.zeros(nbits, dtype=np.double)
    state = sqc.state(2)

    tests = [(
                (sqc.operator(2).Rz(0, r) * state).v
                , BasicGate('R', 0, 0, r)(qm_state, cl_state)[0]) 
                    for r in np.arange(0, 2 * np.pi, 0.1)]

    for expect, got in tests:
        assert expect == pytest.approx(got)

def test_raw_r2():
    nbits = 2
    ndim = 2**nbits
    qm_state = np.zeros(ndim, dtype=np.cdouble)
    qm_state[0] = 1
    cl_state = np.zeros(nbits, dtype=np.double)
    state = sqc.state(2)

    tests = [(
                (sqc.operator(2).Rz(1, r) * state).v
                , BasicGate('R', 1, 0, r)(qm_state, cl_state)[0]) 
                    for r in np.arange(0, 2 * np.pi, 0.1)]

    for expect, got in tests:
        assert expect == pytest.approx(got)

def test_raw_hx11():
    nbits = 2
    ndim = 2**nbits
    qm_state = np.zeros(ndim, dtype=np.cdouble)
    qm_state[0] = 1
    cl_state = np.zeros(nbits, dtype=np.double)
    state = sqc.operator(2).X(0).H(0) * sqc.state(2)
    gate = BasicGate('X', 0, 0, 0.0)
    qm_state_new, cl_state_new, measured = gate(qm_state, cl_state)
    gate = BasicGate('H', 0, 0, 0.0)

    qm_state_new, cl_state_new, measured = gate(qm_state_new, cl_state_new)

    assert state.v == pytest.approx(qm_state_new)
