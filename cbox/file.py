import os
import stat


def cutrepo(x: str) -> str:
    return x[x.find("/") + 1 :]


def rmtree(top):
    for root, dirs, files in os.walk(top, topdown=False):
        for name in files:
            filename = os.path.join(root, name)
            os.chmod(filename, stat.S_IWUSR)
            os.remove(filename)
        for name in dirs:
            os.rmdir(os.path.join(root, name))
    os.rmdir(top)


if __name__ == "__main__":
    print(cutrepo(input()))
