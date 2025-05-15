## Byron Josué Arguedas López, C10606

# Investigación:

Se presentan tres preguntas reales de entrevistas técnicas, enfocadas en el diseño de software, obtenidas de fuentes como *Glassdoor*, *LeetCode Discussions*, *GitHub* y el libro *Cracking the Coding Interview*.

---

## Pregunta 1: ¿Cómo diseñarías un sistema de logging global?

**Fuente:** Cracking the Coding Interview / Glassdoor

### Descripción del problema:
Un sistema necesita registrar eventos, errores e información desde distintas partes de la aplicación. Se requiere una solución centralizada para controlar los niveles de log (info, warning, error, etc.) y evitar múltiples instancias del logger.

### Patrón propuesto:
- **Singleton**
- **Strategy** (opcional para múltiples métodos de logging)

### Justificación:
- `Singleton` garantiza una única instancia global del logger.
- `Strategy` permite intercambiar la forma de loguear (consola, archivo, red, etc.) dinámicamente.

### Implementación (Python):

```python
from abc import ABC, abstractmethod

# Strategy pattern
class LogStrategy(ABC):
    @abstractmethod
    def log(self, message):
        pass

class ConsoleLogger(LogStrategy):
    def log(self, message):
        print(f"[Console] {message}")

class FileLogger(LogStrategy):
    def log(self, message):
        with open("log.txt", "a") as f:
            f.write(f"{message}\n")

# Singleton Logger
class Logger:
    _instance = None

    def __new__(cls, strategy=None):
        if cls._instance is None:
            cls._instance = super(Logger, cls).__new__(cls)
            cls._instance.strategy = strategy or ConsoleLogger()
        return cls._instance

    def set_strategy(self, strategy):
        self.strategy = strategy

    def log(self, message):
        self.strategy.log(message)

# Uso
logger = Logger()
logger.log("Iniciando sistema...")

file_logger = FileLogger()
logger.set_strategy(file_logger)
logger.log("Esto va a un archivo.")
```

---

## Pregunta 2: ¿Cómo diseñarías una aplicación que necesita múltiples algoritmos intercambiables para ordenamiento?

**Fuente:** LeetCode Discussions / Design Patterns Interview Questions

### Descripción del problema:
Un sistema requiere ordenar datos utilizando diferentes algoritmos (e.g., quicksort, bubblesort, mergesort), según el contexto. La selección del algoritmo debe poder cambiarse dinámicamente.

### Patrón propuesto:
- **Strategy**

### Justificación:
`Strategy` permite encapsular los algoritmos en clases independientes, manteniendo el código cliente limpio y flexible para intercambiar comportamientos.

### Implementación (Python):

```python
from abc import ABC, abstractmethod

class SortStrategy(ABC):
    @abstractmethod
    def sort(self, data):
        pass

class QuickSort(SortStrategy):
    def sort(self, data):
        print("Usando QuickSort")
        return sorted(data)

class BubbleSort(SortStrategy):
    def sort(self, data):
        print("Usando BubbleSort")
        return data  # No implementado por simplicidad

class Context:
    def __init__(self, strategy: SortStrategy):
        self.strategy = strategy

    def set_strategy(self, strategy: SortStrategy):
        self.strategy = strategy

    def execute_sort(self, data):
        return self.strategy.sort(data)

# Uso
data = [3, 1, 4, 1, 5]
context = Context(QuickSort())
print(context.execute_sort(data))

context.set_strategy(BubbleSort())
print(context.execute_sort(data))
```

## Pregunta 3: ¿Cómo construirías una interfaz para distintos sistemas operativos sin acoplarte a uno específico?

**Fuente:** Cracking the Coding Interview / GitHub repo de diseño de software

### Descripción del problema:
Queremos crear una interfaz gráfica (GUI) que funcione en múltiples sistemas operativos (Windows, Linux, macOS), sin modificar el código cliente cada vez que cambie el sistema.

### Patrón propuesto:
- Abstract Factory

### Justificación:
Abstract Factory permite crear familias de objetos relacionados (ventanas, botones, menús) sin especificar clases concretas, promoviendo el desacoplamiento del sistema operativo.

### Implementación (Python):

```python
from abc import ABC, abstractmethod

# Productos abstractos
class Button(ABC):
    @abstractmethod
    def render(self): pass

class Window(ABC):
    @abstractmethod
    def render(self): pass

# Productos concretos
class WindowsButton(Button):
    def render(self): print("Renderizando botón en Windows")

class LinuxButton(Button):
    def render(self): print("Renderizando botón en Linux")

class WindowsWindow(Window):
    def render(self): print("Renderizando ventana en Windows")

class LinuxWindow(Window):
    def render(self): print("Renderizando ventana en Linux")

# Abstract Factory
class GUIFactory(ABC):
    @abstractmethod
    def create_button(self): pass

    @abstractmethod
    def create_window(self): pass

# Factories concretas
class WindowsFactory(GUIFactory):
    def create_button(self): return WindowsButton()
    def create_window(self): return WindowsWindow()

class LinuxFactory(GUIFactory):
    def create_button(self): return LinuxButton()
    def create_window(self): return LinuxWindow()

# Cliente
def render_gui(factory: GUIFactory):
    button = factory.create_button()
    window = factory.create_window()
    button.render()
    window.render()

# Uso
os_factory = LinuxFactory()
render_gui(os_factory)
```

## Reflexión:

Si bien es cierto que se requiere bastante conocimiento para reconocer cúal patrón se puede utilizar y porqué, una vez se reconoce el patrón adecuado al caso de aplicación nos brinda muchos beneficios como:

- Reducir el acoplamiento entre componentes.

- Facilitar el mantenimiento y extensión del código.

- Reutilizar soluciones probadas
