def cutrepo(x: str) -> str:
    return x[x.find("/") + 1 :]


if __name__ == "__main__":
    print(cutrepo(input()))
