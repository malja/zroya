import inspect
import sys

# This script generates python stub file from documentation python C/C++ code.
# Stub file is a hint for IDE. It contains a list of all functions and methods in python with docstrings.

# TODO: Find better way for output formatting than this


def GenerateStubFile(path_to_pyd):

    # Add Path to .pyd file with zroya to import path
    sys.path.append(path_to_pyd)

    # Import zroya module
    import _zroya
    from .. import template_enums
    from .. import dismiss_reason

    modules = [
        _zroya,
        template_enums,
        dismiss_reason
    ]

    # Generate .pyi file for zroya module
    with open("./python/zroya.pyi", "w", encoding="utf8") as output:

        for module in modules:

            # Get all classes/functions in python package
            for name, obj in inspect.getmembers(module):

                # TODO: Do not expose Enum class at all
                if "Enum" in name:
                    continue

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

                    # Get all attributes of class
                    for member_name, member_value in inspect.getmembers(obj):

                        # Ignore python members
                        if member_name[0] != "_":
                            # Is it python enum?
                            if hasattr(member_value, "value"):
                                member_value = member_value.value

                            # Is value string
                            if isinstance( member_value, str):
                                # Put " and " around value
                                output.write("\t{} = \"{}\"\n\n".format(member_name, member_value))
                            elif isinstance( member_value, int):
                                # Print number
                                output.write("\t{} = {}\n\n".format(member_name, member_value))

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