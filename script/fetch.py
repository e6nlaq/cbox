"""
/****************************************************************

    script/fetch.py

    Copyright (c) 2023 e6nlaq
    This file is part of cbox.
    See https://github.com/e6nlaq/cbox for more information.

****************************************************************/
"""

from requests import get
from sys import argv


def main(url: str) -> None:
    print(get(url).text)


if len(argv) != 2:
    print("Error: URL must be specified in the command line argument.")
    exit(1)
else:
    main(argv[1])
