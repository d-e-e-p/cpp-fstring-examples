
# cpp_fstring_examples

Examples of using a preprocessing script cpp-fstring to expand python-style 
f-strings in C++ code to equivalent fmt::format (or one day std::format) commands.
This companion site shows how to run cpp-format and shows results of running some examples.

## Credits/Motivation

See [cpp-fstring](https://github.com/d-e-e-p/cpp-fstring)

## Getting Started

<big><pre>
├── Makefile
├── include
│   └── fstr.h
├── examples
│   ├── CMakeLists.txt
│   ├── psrc
│   │   ├── demo_misc.cpp
│   │   ├── ...
│   │   ├── enum_namespace.cpp
│   │   ├── fixed_size_string_buffer.h
│   │   └── tinyply.h
│   ├── src
│   │   ├── demo_misc.cpp
│   │   ├── ...
│   │   ├── enum_namespace.cpp
│   │   ├── fixed_size_string_buffer.h
│   │   └── tinyply.h
│   ├── out
│   │   ├── demo_misc.log
│   │   ├── ...
│   │   └── enum_namespace.log
</pre></big>

Look at the Makefile for debug or release targets.
The cmake command generates run files under `build` dir and then
uses cpp-fstring to convert files under `psrc` dir to `src` dir.
This generated code is compiled and executed. in `examples/CMakeLists.txt`
the following cmake command add cpp-fstring step:

```bash
COMMAND cpp-fstring ${header} -I src -I ../include > ${target}
```




## API


### Tests and Benchmark

### Using cpp_fstring


### Dir Structure


## Authors

* **Sandeep** - [@d-e-e-p](https://github.com/d-e-e-p)

## License

The project is available under the [MIT](https://opensource.org/licenses/MIT) license.
See [LICENSE](LICENSE) file for details
