# Pliki wykonywalne:
### Windows

game.exe

### MacOS

game

# Jak uruchomić:
## MacOS
uruchamiamy plik znajdujący się w folderze  "unix executable file"

$ ./game

Plik może wymagać dodatkowych uprawnień, w tym celu należy skorzystać z komendy:

$ chmod 754 ./game

## Windows
Uruchomić plik game.exe znajdujący się w folderze "windows executable file"

# Kompilacja:
## CLION:
1. Otworzyć folder sourceCode w programie CLion
2. W przypadku kompilatora cmake utworzyć folder cmake-build-debug
3. Do utworzonego folderu skopiować folder assets i config
4. Do folderu sourceCode można wgrać gotowy plik CMakeLists.txt z folderu CMake oraz skopiować folder z lokalna biblioteką SFML dla danego systemu


# Opis folderów:
config - folder zawierający plik zawierający konfigurację gry
assets - folder zawierający tekstury do gry
sourceCode - folder zawierający kod źródłowy
unix executable file - gotowy plik wykonywalny na system MacOS
windows executable file - gotowy plik wykonywalny na system Windows
CMake - folder zawierający plik CMakeLists.txt dla systemu windows oraz systemu MacOS z bibliotekami SMFL pod dane systemy
