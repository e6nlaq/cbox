import argparse
import requests
import os
import shutil

import cbox.__about__ as info
from cbox.path import path
from cbox.filename import cutrepo


def tmp_clear() -> None:
    shutil.rmtree(path + "tmp")
    os.mkdir(path + "tmp")


def main() -> None:
    parser = argparse.ArgumentParser(description="C/C++ library management system")

    parser.add_argument(
        "command",
        type=str,
        help="Runtime Options See README for details.",
        choices=["version", "install"],
    )

    args = parser.parse_args()
    if args.command == "version":
        print(info.__version__)
        exit(0)
    elif args.command == "install":
        inp = input("Enter the repository you wish to install.\n> ")
        installs = inp.split(" ")
        if os.name == "nt":
            os.chdir("C:\\cbox\\tmp")
        else:
            os.chdir(os.path.expanduser("~") + "/.cbox/tmp")

        for x in installs:
            print(f"Installing {x}...")
            if requests.get(f"https://github.com/{x}").status_code != 200:
                print("Error: Repository does not exist or is unreadable.")
                continue
            else:
                os.system(f"git clone https://github.com/{x} --recursive")
                repo = cutrepo(x)
                if os.path.isfile(f"{repo}/cbox.json") and os.path.isdir(
                    f"{repo}/includes"
                ):
                    for f in os.listdir(f"{repo}/includes"):
                        shutil.move(
                            os.path.join(f"{repo}/includes", f), f"{path}/includes"
                        )
                else:
                    print("Error: repository not for cbox")
                    continue

        tmp_clear()


if __name__ == "__main__":
    main()
