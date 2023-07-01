from setuptools import setup
import cbox.__about__ as info
from cbox.path import path
import os

setup(
    name=info.__package_name__,
    version=info.__version__,
    packages=["cbox"],
    # 依存ライブラリ
    install_requires=["argparse", "requests"],
    license=info.__license__,
    author=info.__author__,
    entry_points={"console_scripts": ["cbox=cbox.main:main"]},
)

if os.name == "nt":
    os.makedirs(path + "includes", exist_ok=True)
    os.makedirs(path + "tmp", exist_ok=True)

    f = open(path + "packs.json", "w")
    f.write("{}")
    f.close()

else:
    os.makedirs(path + "includes", exist_ok=True)
    os.makedirs(path + "tmp", exist_ok=True)

    f = open(path + "packs.json", "w")
    f.write("{}")
    f.close()
