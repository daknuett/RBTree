from abc import abstractmethod, ABCMeta
from .backend.raw_state import RawGraphState

class AbstractGraphOperation(metaclass=ABCMeta):
    def __init__(self):
        pass

    @abstractmethod
    def apply_to_raw_state(self, state):
        pass

class CZOperation(AbstractGraphOperation):
    def __init__(self, act, control):
        AbstractGraphOperation.__init__(self)
        self._act = act
        self._control = control

    def apply_to_raw_state(self, state):
        if(not isinstance(state, RawGraphState)):
            raise TypeError("state must be of type RawGraphState, but got {}".format(str(type(state))))

        state.apply_CZ(self._act, self._control)

class CLOperation(AbstractGraphOperation):
    def __init__(self, act, clifford_index):
        AbstractGraphOperation.__init__(self)
        self._act = act

        if(not isinstance(clifford_index, int)):
            raise TypeError("clifford_index must be integer")
        if(0 > clifford_index > 23):
            raise ValueError("clifford_index must be between 0 and 23")
        self._clifford_index = clifford_index

    def apply_to_raw_state(self, state):
        if(not isinstance(state, RawGraphState)):
            raise TypeError("state must be of type RawGraphState, but got {}".format(str(type(state))))

        state.apply_C_L(self._act, self._clifford_index)

class GraphGate(object):
    def __init__(self, operation_list):
        self._operation_list = operation_list
