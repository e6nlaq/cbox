from setuptools import setup
import module.__about__ as info
import os

setup(
    name=info.__package_name__,
    version=info.__version__,
    packages=["module"],
    # 依存ライブラリ
    install_requires=["argparse", "requests"],
    license=info.__license__,
    author=info.__author__,
    entry_points={"console_scripts": ["cbox=module.main:main"]},
)

if os.name == "nt":
    os.makedirs("C:\\cbox\\includes", exist_ok=True)
else:
    os.makedirs("~/.cbox/includes", exist_ok=True)
