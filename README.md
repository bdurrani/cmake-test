# Using CMake

CMake file must be called `CMakeLists.txt`. Casing must match.

## Useful Commands

### Running CMake

```bash
cmake -S . -B ./out/build
```

### Running Make

```bash
make -C ./out/build
```

### Git submodules

```bash
git submodule add <repo path> ./external/folder-name
```

### Sync submodule to tag

https://stackoverflow.com/questions/1777854/how-can-i-specify-a-branch-tag-when-adding-a-git-submodule

```bash
cd submodule_directory
git checkout v1.0
cd ..
git add submodule_directory
git commit -m "moved submodule to v1.0"
git push
```

### Pull submodules

```bash
git submodule update --init --recursive
```

### Build Package

Have to run `cpack` from the build folder.
If you use the CMake extension in VSCode, it will automatically rebuild for you
on any change.

### For the find_library() tutorial

You need to install glew dev

```bash
sudo apt install libglew-dev
```

## Building poppler

You need to install some stuff

For **linux**

```bash
apt-get install --yes --no-install-recommends build-essential cmake ninja-build libjpeg-dev libopenjp2-7-dev qtbase5-dev gobject-introspection libglib2.0-dev libgtk-3-dev libgirepository1.0-dev libnss3-dev ca-certificates libcurl4-nss-dev liblcms2-dev libboost-container-dev

mkdir -p build && cd build
cmake -G Ninja ..
ninja
```