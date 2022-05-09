# C-Console-Template
A template repo for console programs written in C.

## Installation

Dependencies:
* C compiler \*
* meson \*
* ninja \*
* scdoc (optional: man pages)\*

_\* Compile-time dep_

Compilation:
``` sh
git clone ""
cd directory/
meson build/
ninja -C build/
sudo ninja -C build/ install # To install
sudo ninja -C build/ uninstall # To uninstall
```