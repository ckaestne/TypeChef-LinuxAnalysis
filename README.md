# TypeChef Analysis of Linux

Contains various scripts and tools to run TypeChef on Linux.

The setup requires multiple steps. Contact me if there are any issues.

There are two separate setups that are maintained. One is a setup
for Linux 2.6.33.3 (x86 only) that comes with most of the required
files prepared. The other one is a setup to be run on a current
version of Linux (all architectures) that requires additional tools
to extract information from the build scripts and the feature model.

## Setup 

### Directory structure

The scripts to analyze Linux 2.6.33.3 x86 is found in `./linux26333`, the scripts to analyze
the current version in `./master`.

This project depends on TypeChef and, if working on the master, kconfigreader and KBuildMiner.

The script to start TypeChef is expected to be found in directory
`../TypeChef/typechef.sh` (generate script with `sbt mkrun` in the TypeChef
directory). Kconfigreader is expected to be found in `../kconfigreader/run.sh`
(again, generate with `sbt mkrun`) and KBuildMiner in `../KBuildMiner/run.sh`
(follow instructions in Readme file to build with Maven).

You may want to install TypeChef-linuxweb as well as a frontend for the
analysis results. This should go in directory `../linuxweb`.

### Linux source code

Extract the linux source code to `./linux26333/linux` or `./master/linux`.

The script `./linux26333/prepareLinuxTestCases.sh` has some code to automate 
the download and extraction.

### Header files

To run TypeChef on any project, it is necessary to configure header files. We
tend to run TypeChef with a fixed set of header files from a redhat
installation configured in `redhat.properties`. The checked in configuration
file point to a `systems` directory for header files.  That directory is not
part of this repository. If you want to use the exact same headers that we are
using download them here: 

http://www.cs.cmu.edu/~ckaestne/tmp/includes-redhat.tar.bz2

### Compile tools

Run `sbt mkrun` to compile the analysis tools in this project.


## How to run the analysis

Go to `./linux26333` and run `prepareLinuxTestCases.sh` before the first
run. This will create `.pc` files with the file presence conditions
and run the Linux make scripts to generate some needed files.

Afterward run `linuxTestCase.sh` to run the actual analysis. TypeChef parameters
can be adjusted in this file if needed. Several instances of this
script can be executed in parallel.

The analysis will write results and debug informations into various files
with the same name but different extensions from the analyzed `.c` file.
The main output is the `.dbg` file that describes any found problems
in human-readable form (see `.c.xml` for a machine-readable format).
The `linuxTestCase.sh` script will run the analysis on all files that
do not have a `.dbg` file yet. To rerun the analysis on a file, simply
remove the `.dbg` file. The `cleanLinux.sh` script removes all `.dbg` 
files.


If running the analysis on the `master` directory, you first need to extract
the feature models, file presence conditions, and other kbuild parameters with 
`genPCs.sh`, `genKbuild.sh` and `genFMs.sh`. 
The files will be placed in the `pcs` directory and used
for the remaining analysis. For `linux26333` those files are already
checked in, but can be recreated with the corresponding scripts.

## Further tools

The project contains several Scala tools to automate some analysis
or debugging tasks. 

One of the most useful tools is CheckExpr (easily accessible through
`checkexpr.sh`) which reads a formula from a file `formula`
and checks whether it is satisfiable or a tautology.
