import python
import inspect

# This script generates python stub file from documentation python C/C++ code.
# Stub file is a hint for IDE. It contains a list of all functions and methods in python with docstrings.

# TODO: Documentation for class attributes
# TODO: Find better way for output formatting than this
# TODO: Call this automatically

with open("python.pyi", "w", encoding="utf8") as output:

    # Get all classes/functions in python package
    for name, obj in inspect.getmembers(python):

        # Is it a package function
        if inspect.isbuiltin(obj):

            # Print def <function_name>(<function_parameters>):
            output.write("def {}{}:\n".format(name, inspect.signature(obj)))
            # Print functions docstring
            output.write("\t\"\"\"\n\t{}\n\t\"\"\"\n\tpass\n\n".format(inspect.getdoc(obj).replace("\n", "\n\t")))

        # Is it a class
        if inspect.isclass(obj):
            # Print class <class_name>:
            output.write("class {}:\n".format(name))
            # Print class docstring
            output.write("\t\"\"\"\n\t{}\n\t\"\"\"\n\n".format(obj.__doc__))

            # Get all methods from class
            for cname, cobj in inspect.getmembers(obj):
                # Is it a method? Ignoring those starting with undercore, because python does not set them.
                if inspect.ismethoddescriptor(cobj) and cname[0] != "_":
                    # Get method signature. Replace leading and trailing bracket, because I have to add self parameter
                    signature = str(inspect.signature(cobj)).replace("(", "").replace(")", "")
                    # Print: def <function_name>(self, <function_parameters>):
                    output.write("\tdef {}(self, {}):\n".format(cname, signature))
                    # Print methods docstring
                    output.write("\t\t\"\"\"\n\t\t{}\n\t\t\"\"\"\n\t\tpass\n\n".format(inspect.getdoc(cobj).replace("\n", "\n\t\t")))