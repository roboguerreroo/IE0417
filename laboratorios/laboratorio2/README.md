## Autor: Byron Josué Arguedas López
## Carnet: C10606

# Parte 1: Git y control de versiones
# Main levels:
## Introduction:
![ejercicio 1](<Screenshot 2025-04-06 182145.png>)
![ejercicio 2](<Screenshot 2025-04-06 182355.png>)
![ejercicio 3](<Screenshot 2025-04-06 183114.png>)
![ejercicio 3](<Screenshot 2025-04-06 183436.png>)
**Objetivo:**  
Aprender lo básico de los commits y cómo moverte entre ramas simples.

**Comandos principales:**
- `git commit` — Guarda los cambios en el repositorio.
- `git branch` — Lista o crea nuevas ramas.
- `git checkout` — Cambia entre ramas o revisa commits específicos.
- `git log` — Muestra el historial de commits.

---

## Ramping Up:
![ejercicio 3](<Screenshot 2025-04-06 183726.png>)
![ejercicio 3](<Screenshot 2025-04-06 184016.png>)
![ejercicio 3](<Screenshot 2025-04-06 190407.png>)
![ejercicio 3](<Screenshot 2025-04-06 212750.png>)

**Objetivo:**  
Introducción a las referencias relativas para moverte por el historial de commits.

**Comandos principales:**
- `HEAD` — Referencia al último commit en tu rama actual.
- `HEAD^` — El commit anterior al actual.
- `HEAD~n` — "n" commits atrás desde `HEAD`.
- `git checkout HEAD^` — Cambiarte al commit anterior.
- `git log --oneline` — Ver un resumen de los commits.

---

## Moving Work Aroung:
![ejercicio 3](<Screenshot 2025-04-07 135337.png>)
![ejercicio 3](<Screenshot 2025-04-07 135806.png>)

**Objetivo:**  
Aprender a mover commits y modificar el historial con rebase interactivo.

**Comandos principales:**
- `git rebase -i HEAD~n` — Reescribe el historial reciente.
- `pick`, `squash`, `reword` — Opciones dentro del rebase interactivo para elegir qué hacer con cada commit.
- `git cherry-pick <commit>` — Aplicar un commit específico de otra rama.

---

## A mixed bag:
![ejercicio 3](<Screenshot 2025-04-07 135954.png>)
![ejercicio 3](<Screenshot 2025-04-07 143314.png>)
![ejercicio 3](<Screenshot 2025-04-07 143612.png>)
![ejercicio 3](<Screenshot 2025-04-07 143822.png>)
![ejercicio 3](<Screenshot 2025-04-07 143948.png>)

**Objetivo:**  
Aprender técnicas y trucos variados para manejar el historial de Git.

**Comandos principales:**
- `git cherry-pick` — Extrae commits específicos.
- `git reflog` — Muestra todos los movimientos recientes, incluso los que se han "perdido".
- `git reset` — Regresa el estado del branch a un commit anterior.
- `git revert` — Crea un nuevo commit que deshace los cambios de un commit anterior.

---

## Levels done:
![ejercicio 3](<Screenshot 2025-04-07 144016.png>)

---

# Remote Levels:
## Push and pull:
![alt text](<Screenshot 2025-04-08 154534.png>)
![alt text](<Screenshot 2025-04-08 154807.png>)
![alt text](<Screenshot 2025-04-08 154937.png>)
![alt text](<Screenshot 2025-04-08 155118.png>)
![alt text](<Screenshot 2025-04-08 155705.png>)
![alt text](<Screenshot 2025-04-08 155859.png>)
![alt text](<Screenshot 2025-04-08 160445.png>)
![alt text](<Screenshot 2025-04-08 161019.png>)

**Objetivo:**  
Aprender a trabajar con repositorios remotos para colaborar y compartir tu trabajo.

**Comandos principales:**
- `git clone <url>` — Clona un repositorio remoto a tu máquina local.
- `git remote -v` — Lista las URLs de los repositorios remotos configurados.
- `git fetch` — Descarga cambios desde el repositorio remoto pero no los integra.
- `git pull` — Descarga e integra cambios del repositorio remoto.
- `git push` — Envía tus commits al repositorio remoto.

---

## To origin and beyond:
![alt text](<Screenshot 2025-04-08 161323.png>)
![alt text](<Screenshot 2025-04-08 161548.png>)
![alt text](<Screenshot 2025-04-08 174441.png>)
![alt text](<Screenshot 2025-04-08 174547.png>)
![alt text](<Screenshot 2025-04-08 174752.png>)
![alt text](<Screenshot 2025-04-08 175014.png>)
![alt text](<Screenshot 2025-04-08 175349.png>)
![alt text](<Screenshot 2025-04-08 180124.png>)

**Objetivo:**  
Avanzar en la gestión avanzada de repositorios remotos, incluyendo ramas múltiples y colaboración eficiente.

**Comandos principales:**
- `git push <remote> <branch>` — Envía una rama específica a un remoto.
- `git pull <remote> <branch>` — Trae los últimos cambios de una rama remota específica.
- `git remote add <name> <url>` — Añade un nuevo remoto.
- `git remote remove <name>` — Elimina un remoto existente.
- `git remote rename <old> <new>` — Renombra un remoto.

---

## Levels done:
![alt text](<Screenshot 2025-04-08 180137.png>)

---

# Parte 2: Documentación automática en C++ y Python

Este laboratorio incluye documentación generada automáticamente para dos lenguajes de programación: **C++** y **Python**.

## Enlaces a la documentación

- **C++**: [Ver Documentación C++](https://sparkly-cannoli-8029a2.netlify.app/index.html)
- **Python**: [Ver Documentación Python](https://67f44e9d289a590075994d0f--joyful-lamington-7a7156.netlify.app/)
