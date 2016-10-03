# FastPD

[![Build Status](https://travis-ci.org/Gnimuc/FastPD.svg?branch=master)](https://travis-ci.org/Gnimuc/FastPD)
[![Build status](https://ci.appveyor.com/api/projects/status/1cd4q3oyva4dil4m?svg=true)](https://ci.appveyor.com/project/Gnimuc/fastpd)

This repo is used as a generator for building Nikos Komodakis's FastPD MRF optimization algorithm as a shared library through [Travis CI](https://travis-ci.org) and [AppVeyor](https://ci.appveyor.com). Those generated binaries are mainly used by [FastPD.jl](https://github.com/Gnimuc/FastPD.jl) package.

>The provided optimization code can be used as a tool for minimizing the energy of a discrete Markov Random Field (MRF). It is a demo version of FastPD, and is intended to show only part of that algorithm's functionality.

Click [here](http://imagine.enpc.fr/~komodakn/software.html) for further details.

## Build
```
mkdir build && cd build
cmake ..
make
```

## LICENSE
Please refer to [LICENSE.md](https://github.com/Gnimuc/FastPD/blob/master/LICENSE.md).
