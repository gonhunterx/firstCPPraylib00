# Hello C++

## Requirements

- [Download VSCode from here](https://code.visualstudio.com/Download)
- [Download Git from here](https://git-scm.com/download/win)
- [Download Visual Studio Build Tools from here](https://visualstudio.microsoft.com/en/downloads/)
- [Download CMake (binary distribution) from here](https://cmake.org/download/)

Within VSCode, install extensions:
- C/C++ (from Microsoft)
- CMake Tools (from Microsoft)

Open the HelloCpp folder with VSCode (File -> OpenFolder...)

## CMake

You can either use CMake integration in VSCode or create custom VSCode tasks to run CMake with command lines.

Here we are going to describe both.

### Introduction

CMake lets you **configure** your project, then **build** it.

**configure** means that CMake reads the **CMakeLists.txt** file at the root of you project, detects where is your compiler, and list all the source files that need to be built. (and does all other things too)

**build** means that CMake is going to use the information found in the **configure** steps to run the compiler on the source files to make a binary. It can be a library (.dll, .lib), or an executable (.exe).

### Command line

> Warning: You have to open your VSCode from the **"x64 Native Tools Command Prompt for VS YYYY"**. This can be found from the Start menu, from there, just run `code` to launch VSCode. If you forget about this, CMake will not be able to find the compiler (msvc) you got from Visual Studio Build Tools.

Open a terminal from VSCode Menu: Terminal -> New Terminal

Now you should (have to) be at the root of your project directory.

The minimum commands to build your project with CMake are:

#### Configure Stage

``` batch
cmake . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
```

`.` means the current directory where the CMakeLists.txt can be found.

`-B build` asks to create directory named **build** (from the current directory) and prepare the build process in it.

`-G Ninja` asks to use a simplified project generation on Windows. As we are developping from VSCode, it is enough.

`-DCMAKE_BUILD_TYPE=Debug` asks to build with debug symbols, optimizations off, allowing you to run your program with the debugger.

`-DCMAKE_BUILD_TYPE=Release` asks to build without debug symbols, and optimizations on. The debugger could still be used, but would struggle (a lot) to show meaning information.

> If your **CMakeLists.txt** has problems (describing your project, where to find the sources, etc.), errors will show up at this stage.

#### Build Stage

``` batch
cmake --build build
```

`--build build` asks to build the project from the directory you just prepared named **build**

> If your sources (cpp files, etc.) have problems, errors will show up at this stage.

After a successful build, your binary is available in **build**, here it will be `build\hellocpp.exe`.

### VSCode Integration

At the bottom of the VSCode window, you have CMake buttons/options.

#### Kit Selection

Locale the kit selection button, it states "No Kit Selected" the first time.

Click and choose your "Visual Studio Build Tools YYYY Release - amd64" to build 64 bits binaries.

#### Configure Stage

Locate the build variant button, by default "CMake: [Debug]: Ready".

Click and choose the build variant among those listed, including "Debug" and "Release".

#### Build Stage

Locate the build button, "Build" with a cog next to it.

Click it to build the project.

**Keyboard Shortcut: F7**

#### Run

Locate the play button, play icon.

Click it to run your program.

**Keyboard Shortcut: Shift+F5**

#### Debug

Locate the debug button, bug icon.

Click it to run your program with the debugger.

**Keyboard Shortcut: Ctrl+F5**

## Git

Open a terminal from VSCode Menu: Terminal -> New Terminal

### Configuration

Set your name and email address:

``` batch
git config --global user.name "John Doe"
git config --global user.email "john.doe@example.net"
```

These information are just meant to be used when you create Git **commits** (saves of your work) to give an author to them. You don't even need to define these when you are just cloning Git repositories.

> Privacy: Be aware that these information are meant to be public if you publish your repository publicly on GitHub or other services.

### VSCode Integration

There are many things to say about how to use Git with the command line. But VSCode has a good enough Git integration in one of the icons on the left side bar.

From there, you can **initialize** a Git repository out of your project folder.

You can then, **stage** files you want specifically save in a commit. (+ sign button)

If you don't stage any file, they will all be staged to be commited by default.

You can write a message to identify your **commit**.

Click the **"Commit" button** when you have written your message, and that you have carefully reviewed the files being committed (that is, all of them if non have been manually staged, or only the one manually staged).

### Commit Messages

How to write my commit message?

There are no standard way, but there are good practices that many developers like. One of them is describing what the changes saved into your commit, are doing for the project.

As an example, if you were adding a logging library to your project, you can say: "Add logging library", or "Add logs", etc.

- Imperative verb
- High level description of the changes
- Avoid describing you are adding a file, or removing a line, etc.
- Avoid using words like "the", etc. to keep it concise

### Good practices

Commit often! Small changes that does something, have to be committed with their own commit message to identify them.