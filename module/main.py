import argparse
import __about__ as info
import requests


def main() -> None:
    parser = argparse.ArgumentParser(description="C/C++ library management system")

    parser.add_argument(
        "command",
        type=str,
        help="Runtime Options See README for details.",
        choices=["version"],
    )

    args = parser.parse_args()
    if args.command == "version":
        print(info.__version__)
        exit(0)


if __name__ == "__main__":
    main()
