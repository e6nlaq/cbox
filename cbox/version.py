# aがインストールするバージョン
def version_check(v1: str, v2: str) -> bool:
    a: list[int] = list(map(int, v1.split(".")))
    b: list[int] = list(map(int, v2.split(".")))

    for i in range(3):
        if a[i] > b[i]:
            return True

    return False
