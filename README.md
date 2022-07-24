# C-Console-Template
A template repo for console programs written in C.

## Building

Dependencies:
* GCC/Clang \*
* meson (>=0.59.0) \*
* ninja \*
* scdoc (optional: man pages) \*

	_\* Compile-time dependency_

``` sh
git clone ""
cd directory/
meson build/
ninja -C build/
```
``` sh
sudo ninja -C build/ install # To install
```
``` sh
sudo ninja -C build/ uninstall # To uninstall
```