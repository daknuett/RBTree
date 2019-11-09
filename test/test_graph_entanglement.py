import pytest

from pyqcs import State, H, X, Z, CZ, list_to_circuit
from pyqcs.graph.backend.raw_state import RawGraphState
from pyqcs.graph.util import graph_lists_to_naive_state

VOP_H = 0
VOP_Z = 5
VOP_X = 14

@pytest.fixture
def graph_zero_state_10():
    g = RawGraphState(10)
    for i in range(10):
        g.apply_C_L(i, VOP_H)

    return g

@pytest.fixture
def naive_zero_state_10():
    return State.new_zero_state(10)

@pytest.fixture
def graph_plus_state_10():
    return RawGraphState(10)

@pytest.fixture
def naive_plus_state_10():
    state = State.new_zero_state(10)
    circuit = list_to_circuit([H(i) for i in range(10)])

    return circuit * state

def test_CZ_zero_state(graph_zero_state_10):
    g = graph_zero_state_10
    g.apply_CZ(0, 1)

    lists = g.to_lists()

    print(lists)
    assert lists == ([2] * 10, [[1], [0]] + [[]]*8)


def test_many_CZ_zero_state(graph_zero_state_10, naive_zero_state_10):
    edges = [(1, 2), (2, 0), (5, 9), (8, 4), (7, 0), (5, 7), (8, 9)]
    circuit = list_to_circuit([CZ(*e) for e in edges])
    g = graph_zero_state_10
    for e in edges:
        g.apply_CZ(*e)

    converted = graph_lists_to_naive_state(g.to_lists())

    assert converted == circuit * naive_zero_state_10

def test_many_CZ_plus_state(graph_plus_state_10, naive_plus_state_10):
    edges = [(1, 2), (2, 0), (5, 9), (8, 4), (7, 0), (5, 7), (8, 9)]
    circuit = list_to_circuit([CZ(*e) for e in edges])
    g = graph_plus_state_10
    with pytest.raises(NotImplementedError):
        for e in edges:
            g.apply_CZ(*e)

    #converted = graph_lists_to_naive_state(g.to_lists())

    #assert converted == circuit * naive_zero_state_10

def test_many_CZ_clear_vops(graph_zero_state_10, naive_zero_state_10):
    edges = [(1, 2)
            , (2, 0)
            , (5, 9)
            , (8, 4)
            , (7, 0)
            , (5, 7)
            , (8, 9)
            , (1, 4)
            , (2, 5)
            , (4, 5)]
    circuit1 = list_to_circuit([CZ(*e) for e in edges])
    state1 = circuit1 * naive_zero_state_10
    g = graph_zero_state_10
    for e in edges:
        g.apply_CZ(*e)

    g.apply_C_L(2, VOP_X)
    g.apply_C_L(4, VOP_H)
    state2 = (H(2) | H(4)) * state1
    g.apply_CZ(2, 4)
    state3 = CZ(2, 4) * state2

    print(g.to_lists())
    print("converted", graph_lists_to_naive_state(g.to_lists()))
    print("state", state3)
    assert graph_lists_to_naive_state(g.to_lists()) == state3


def test_many_CZ_clear_vops_precomputed():
    g = RawGraphState(3)
    for i in range(3):
        g.apply_C_L(i, VOP_H)
    s = State.new_zero_state(3)

    s = (CZ(1, 0) | CZ(2, 0) | CZ(1, 2)) * s
    g.apply_CZ(1, 0)
    g.apply_CZ(2, 0)
    g.apply_CZ(1, 2)

    print("naive",s)
    print("lists", g.to_lists())
    print("converted", graph_lists_to_naive_state(g.to_lists()))
    assert graph_lists_to_naive_state(g.to_lists()) == s

    s = (H(0) | X(1)) * s
    g.apply_C_L(0, VOP_H)
    g.apply_C_L(1, VOP_X)

    print("naive",s)
    print("lists", g.to_lists())
    print("converted", graph_lists_to_naive_state(g.to_lists()))
    assert graph_lists_to_naive_state(g.to_lists()) == s

    s = CZ(1, 0) * s
    g.apply_CZ(1, 0)

    print("naive",s)
    print("lists", g.to_lists())
    print("converted", graph_lists_to_naive_state(g.to_lists()))
    assert graph_lists_to_naive_state(g.to_lists()) == s


if __name__ == "__main__":
    g = RawGraphState(10)
    for i in range(10):
        g.apply_C_L(i, VOP_H)
    s = State.new_zero_state(10)

    test_many_CZ_clear_vops(g, s)
