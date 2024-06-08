lines, character = list(map(int, input().split()))
l = [[] for i in range(character + lines)]

for i in range(lines):
    s = input()

    for x in range(character):
        if s[x] == "#":
            l[x + lines].append(i)
            l[i].append(x + lines)

control = set()
control.add(0)
queue = [(0, 0)]
out = -1

# print(queue)
# print(control)
# print(l)

while queue:
    p, q = queue.pop(0)

    if (lines - 1) == p:
        out = q
        break

    for k in l[p]:
        if k not in control:
            queue.append((k, q + 1))
            control.add(k)

print(out)

		   	  	 		  	 	  	 	 	