# gmock-more-args [![Build Status](https://app.travis-ci.com/apriorit/gmock-more-args-sample.svg?branch=master)](https://app.travis-ci.com/apriorit/gmock-more-args-sample)
This header-only library add [gMock](https://github.com/google/googletest/blob/master/googlemock) functionality for methods with number of arguments from 11 up to 15.

- [Introduction](#introduction)
- [Compatibility](#compatibility)
- [Usage](#usage)
  - [Step 1: Adding includes](#step-1-adding-includes)
  - [Step 2: Declare mock method with more than 10 arguments](#step-2-declare-mock-method-with-more-than-10-arguments)
- [Samples](#samples)
- [License](#license)
- [Version history](#version-history)
  - [Version 1.1.1 (18 Feb 2022)](#version-111-18-feb-2022)
  - [Version 1.1.0 (18 Apr 2019)](#version-110-18-apr-2019)
  - [Version 1.0.1 (18 Apr 2019)](#version-101-18-apr-2019)
  - [Version 1.0.0 (12 Oct 2017)](#version-100-12-oct-2017)

# Introduction

[gMock](https://github.com/google/googletest/blob/master/googlemock) is a C++ framework for writing [mock classes](https://en.wikipedia.org/wiki/Mock_object). Mock methods are defined by `MOCK_METHODn()` marco. However it can handle up to 10 arguments. But in some cases we need more.

For example we have such declaration of `WINAPI` function with 11 arguments:
```cpp
NTSTATUS WINAPI NtCreateUserProcess(
    PHANDLE                         phProcess,
    PHANDLE                         threadHandle,
    ACCESS_MASK                     processDesiredAccess,
    ACCESS_MASK                     threadDesiredAccess,
    POBJECT_ATTRIBUTES              processObjectAttributes,
    POBJECT_ATTRIBUTES              threadObjectAttributes,
    ULONG                           processFlags,
    ULONG                           threadFlags,
    PRTL_USER_PROCESS_PARAMETERS    processParameters,
    PVOID                           createInfo,
    PVOID                           attributeList
    );
```
Before [gmock-more-args](https://github.com/apriorit/gmock-more-args) we had to wrap arguments into structure:
```cpp
struct CreateUserProcessParams
{
    PHANDLE                         phProcess;
    PHANDLE                         ThreadHandle;
    ACCESS_MASK                     ProcessDesiredAccess;
    ACCESS_MASK                     ThreadDesiredAccess;
    POBJECT_ATTRIBUTES              ProcessObjectAttributes;
    POBJECT_ATTRIBUTES              ThreadObjectAttributes;
    ULONG                           ProcessFlags;
    ULONG                           ThreadFlags;
    PRTL_USER_PROCESS_PARAMETERS    ProcessParameters;
    PVOID                           CreateInfo;
    PVOID                           AttributeLis;
};
```
And pass it like a single argument:
```cpp
MOCK_METHOD1(MockNtCreateUserProcess, NTSTATUS(CreateUserProcessParams params));
```
With [gmock-more-args](https://github.com/apriorit/gmock-more-args) we just use `MOCK_METHOD11`:
```cpp
MOCK_GLOBAL_FUNC11(MockNtCreateUserProcess, NTSTATUS(
    PHANDLE                         phProcess,
    PHANDLE                         ThreadHandle,
    ACCESS_MASK                     ProcessDesiredAccess,
    ACCESS_MASK                     ThreadDesiredAccess,
    POBJECT_ATTRIBUTES              ProcessObjectAttributes,
    POBJECT_ATTRIBUTES              ThreadObjectAttributes,
    ULONG                           ProcessFlags,
    ULONG                           ThreadFlags,
    PRTL_USER_PROCESS_PARAMETERS    ProcessParameters,
    PVOID                           CreateInfo,
    PVOID                           AttributeLis
    ));
```

# Compatibility
Compatibility of [gmock-more-args](https://github.com/apriorit/gmock-more-args) with different [gMock versions](https://github.com/google/googletest/releases/):
| gmock-more-args | gMock |
|--|--|
| 1.0.x | 1.8.0 | 
| - | 1.8.1 | 
| 1.1.x | 1.10.0-1.11.0 |

# Usage

## Step 1: Adding includes
At first your project needs to know about [gmock-more-args](https://github.com/apriorit/gmock-more-args).

1. Add `gmock-more-args/include` to the project include paths.
2. Add `#include <gmock-more-args/gmock-more-args.h>` after [gMock](https://github.com/google/googletest/blob/master/googlemock) include.

## Step 2: Declare mock method with more than 10 arguments
Syntax is exactly the same as in gMock. For example, to mock method `methodWith11Args` with 11  `int` arguments and `int` result you have to write declaration: 
```cpp
MOCK_METHOD11(methodWith11Args, int(int, int, int, int, int, int, int, int, int, int, int));
```

# Samples
Samples live in the separate [repository](https://github.com/apriorit/gmock-more-args-sample).

# License
[gmock-more-args](https://github.com/apriorit/gmock-more-args) is licensed under the MIT License. You can freely use it in your commercial or opensource software.

# Version history

## Version 1.1.1 (18 Feb 2022)
- Added compatibility with gMock 1.11.0

## Version 1.1.0 (18 Apr 2019)
- Added compatibility with gMock 1.10.0

## Version 1.0.1 (18 Apr 2019)
- Added compatibility with gMock 1.8.0

## Version 1.0.0 (12 Oct 2017)
- Initial public release
