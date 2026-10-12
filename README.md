# Serpiente

Serpiente es un videojuego de consola para Windows inspirado en el juego clásico de la serpiente. Controla a Quetzalcóatl, consigue puntos y responde preguntas sobre deidades mexicas para conservar tus vidas.

## Características principales

- Modos de dificultad fácil y difícil.
- Registro de nuevos jugadores e inicio de sesión.
- Controles con las flechas del teclado.
- Tres vidas; al chocar con una pared o con el cuerpo, una respuesta correcta a una pregunta permite conservar la vida.
- Diez puntos por cada objetivo que recoge la serpiente.
- Consulta información sobre deidades, reglas y marcadores.
- Guardado de jugadores y puntuaciones en `jugadores.txt`.

## Tecnologías utilizadas

- C++.
- API de consola de Windows (`windows.h`, `conio.h`).
- Archivos de texto para las reglas, las preguntas y los datos de jugadores.
- MinGW-w64 / `g++` para compilar, o Dev-C++ para abrir el proyecto existente.

## Requisitos previos

- Windows, ya que el programa usa la API de consola de Windows.
- Un compilador `g++` para Windows (por ejemplo, MinGW-w64) agregado al `PATH`; alternativamente, Dev-C++ con su compilador configurado.
- Git, solo si se va a clonar el repositorio.

## Instalación

1. Clona el repositorio:

   ```powershell
   git clone <URL-del-repositorio>
   cd <carpeta-del-repositorio>
   ```

   Sustituye `<URL-del-repositorio>` por la URL del repositorio y `<carpeta-del-repositorio>` por la carpeta creada al clonarlo.

2. Comprueba que `g++` esté disponible:

   ```powershell
   g++ --version
   ```

3. Desde la carpeta raíz del proyecto, compila el programa:

   ```powershell
   g++ main.cpp -o Serpiente.exe
   ```

No se requieren librerías externas. Si usas Dev-C++, también puedes abrir `Serpiente.dev` y compilar el proyecto desde el IDE.

## Uso

Ejecuta el programa desde la carpeta raíz del proyecto para que pueda encontrar sus archivos de datos:

```powershell
.\Serpiente.exe
```

Usa las flechas arriba y abajo para recorrer los menús y `Enter` para seleccionar. Durante la partida, mueve a Quetzalcóatl con las flechas del teclado. En el menú principal puedes empezar una partida, consultar las deidades, leer las reglas o ver los marcadores.

Los archivos `jugadores.txt`, `preguntas2.txt` y `reglas.txt` deben estar en la carpeta de ejecución. El programa lee las preguntas desde `preguntas2.txt` y actualiza los datos de jugadores y puntuaciones en `jugadores.txt`.

## Contribución

Las contribuciones son bienvenidas. Para proponer un cambio:

1. Crea una rama para tu mejora o corrección.
2. Mantén los cambios enfocados y conserva el formato esperado por los archivos de datos.
3. Comprueba que el proyecto compile con `g++ main.cpp -o Serpiente.exe`.
4. Abre un *pull request* con un resumen del cambio y las pruebas realizadas.
