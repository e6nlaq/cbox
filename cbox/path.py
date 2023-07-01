import os

if os.name == "nt":
    path = "C:\\cbox\\"
else:
    path = os.path.expanduser("~") + "/.cbox/"
