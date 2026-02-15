def user_logic(l, r):
    if l == r:
        return 0
    return r - max(l, (r // 2) + 1)


# ---- Input Handling ----
t = int(input().strip())
for _ in range(t):
    l, r = map(int, input().split())
    print(user_logic(l, r))
