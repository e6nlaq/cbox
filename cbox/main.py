import argparse
import requests
import os
import shutil
import json

import cbox.__about__ as info
from cbox.path import path
from cbox.file import cutrepo, rmtree
from cbox.version import version_check


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

        success = 0
        skip = 0
        for x in installs:
            print(f"Installing {x}...")
            if requests.get(f"https://github.com/{x}").status_code != 200:
                print("Error: Repository does not exist or is unreadable.")
                continue
            else:
                os.system(f"git clone https://github.com/{x} --recursive")
                repo = cutrepo(x)
                if os.path.isfile(f"{repo}/cbox.json"):
                    with open(f"{repo}/cbox.json") as f:
                        d: dict = json.load(f)

                    with open(f"{path}/packs.json") as f:
                        pack: dict = json.load(f)

                    if not os.path.isdir(repo + "/" + d["include"]):
                        print("Error: repository not for cbox")
                        continue

                    if not x in pack:
                        pack[x] = {
                            "version": d["version"],
                            "description": d["description"],
                            "author": d["author"],
                            "files": [],
                        }
                    elif version_check(d["version"], pack[x]["version"]):
                        skip += 1
                        continue

                    for req in d["requests"]:
                        installs.append(req)

                    for f in os.listdir(f"{repo}/includes"):
                        shutil.move(
                            os.path.join(f"{repo}/includes", f),
                            os.path.join(f"{path}includes", f),
                        )
                        pack[x]["files"].append(os.path.join(f"{path}includes", f))
                    success += 1

                    f = open(f"{path}/packs.json", "w")
                    f.write(json.dumps(pack, indent=4))
                    f.close()
                else:
                    print("Error: repository not for cbox")
                    continue

        os.chdir(path)
        rmtree(f"{path}/tmp")
        print("------------------------------------------------------")
        print(
            f"Executed: {len(installs)}, Success: {success}, Failure: {len(installs)-success-skip}, Skip: {skip}"
        )
        print("------------------------------------------------------")


if __name__ == "__main__":
    main()
