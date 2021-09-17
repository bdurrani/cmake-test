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