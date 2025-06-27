# observer.py
from abc import ABC, abstractmethod

class Observer(ABC):
    @abstractmethod
    def update(self, data):
        pass
